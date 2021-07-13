#include <stdint.h>
#include <stdbool.h>
#include "util.h"
#include "matrix.h"
#include "debounce.h"
#include "quantum.h"
#include "split_util.h"
#include "config.h"
#include "transport.h"

#define ERROR_DISCONNECT_COUNT 5
#define ROWS_PER_HAND (MATRIX_ROWS / 2)

static pin_t row_pins[MATRIX_ROWS] = MATRIX_ROW_PINS;
static pin_t col_pins[MATRIX_COLS] = MATRIX_COL_PINS;

/* center key pushed state is 1. all others are 0 */
static const uint8_t col_pushed_states[MATRIX_COLS] = {0, 0, 1, 0, 0};

/* matrix state(1:on, 0:off) */
matrix_row_t raw_matrix[MATRIX_ROWS];  // raw values
matrix_row_t matrix[MATRIX_ROWS];      // debounced values

// row offsets for each hand
uint8_t thisHand, thatHand;

// user-defined overridable functions
__attribute__((weak)) void matrix_slave_scan_user(void) {}

/* delay between changing matrix pin state and reading values */
void matrix_output_select_delay(void) { wait_us(30); }

void matrix_output_unselect_delay(void) { wait_us(200); }

static inline void setPinOutput_writeHigh(pin_t pin) {
    ATOMIC_BLOCK_FORCEON {
        setPinOutput(pin);
        writePinHigh(pin);
    }
}

static inline void setPinOutput_writeLow(pin_t pin) {
    ATOMIC_BLOCK_FORCEON {
        setPinOutput(pin);
        writePinLow(pin);
    }
}

static inline void setPinInputHigh_atomic(pin_t pin) {
    ATOMIC_BLOCK_FORCEON { setPinInputHigh(pin); }
}

static inline void setPinInputLow_atomic(pin_t pin) {
    ATOMIC_BLOCK_FORCEON { setPinInputLow(pin); }
}
// matrix code

static void select_row(uint8_t row) { setPinOutput_writeHigh(row_pins[row]); }

static void unselect_row(uint8_t row) { setPinInputLow_atomic(row_pins[row]); }

static void unselect_rows(void) {
    for (uint8_t x = 0; x < ROWS_PER_HAND; x++) {
        setPinInputLow_atomic(row_pins[x]);
    }
}

static void init_pins(void) {
    unselect_rows();
    for (uint8_t x = 0; x < MATRIX_COLS; x++) {
        setPinInputHigh_atomic(col_pins[x]);
    }
}

static bool read_cols_on_row(matrix_row_t current_matrix[], uint8_t current_row) {
    // Start with a clear matrix row
    matrix_row_t current_row_value = 0;

    // Select row
    select_row(current_row);
    matrix_output_select_delay();

    // For each col...
    for (uint8_t col_index = 0; col_index < MATRIX_COLS; col_index++) {
        // Select the col pin to read (active low)
        uint8_t pin_state = readPin(col_pins[col_index]);

        // Populate the matrix row with the state of the col pin
        current_row_value |= (pin_state != col_pushed_states[col_index] ? 0 : (MATRIX_ROW_SHIFTER << col_index));
    }

    // Unselect row
    unselect_row(current_row);
    matrix_output_unselect_delay();  // wait for row to turn off.
    /* if (current_row + 1 < MATRIX_ROWS) { */
    /*     matrix_output_unselect_delay();  // wait for row signal to go HIGH */
    /* } */

    // If the row has changed, store the row and return the changed flag.
    if (current_matrix[current_row] != current_row_value) {
        current_matrix[current_row] = current_row_value;
        return true;
    }
    return false;
}

void matrix_init(void) {
    split_pre_init();

    // Set pinout for right half if pinout for that half is defined
    if (!isLeftHand) {
#ifdef MATRIX_ROW_PINS_RIGHT
        const pin_t row_pins_right[MATRIX_ROWS] = MATRIX_ROW_PINS_RIGHT;
        for (uint8_t i = 0; i < MATRIX_ROWS; i++) {
            row_pins[i] = row_pins_right[i];
        }
#endif
#ifdef MATRIX_COL_PINS_RIGHT
        const pin_t col_pins_right[MATRIX_COLS] = MATRIX_COL_PINS_RIGHT;
        for (uint8_t i = 0; i < MATRIX_COLS; i++) {
            col_pins[i] = col_pins_right[i];
        }
#endif
    }

    thisHand = isLeftHand ? 0 : (ROWS_PER_HAND);
    thatHand = ROWS_PER_HAND - thisHand;

    // initialize key pins
    init_pins();

    // initialize matrix state: all keys off
    for (uint8_t i = 0; i < MATRIX_ROWS; i++) {
        raw_matrix[i] = 0;
        matrix[i]     = 0;
    }

    debounce_init(ROWS_PER_HAND);

    matrix_init_quantum();

    split_post_init();
}

bool matrix_post_scan(void) {
    bool changed = false;
    if (is_keyboard_master()) {
        static uint8_t error_count;

        matrix_row_t slave_matrix[ROWS_PER_HAND] = {0};
        if (!transport_master(matrix + thisHand, slave_matrix)) {
            error_count++;

            if (error_count > ERROR_DISCONNECT_COUNT) {
                // reset other half if disconnected
                for (int i = 0; i < ROWS_PER_HAND; ++i) {
                    matrix[thatHand + i] = 0;
                    slave_matrix[i]      = 0;
                }

                changed = true;
            }
        } else {
            error_count = 0;

            for (int i = 0; i < ROWS_PER_HAND; ++i) {
                if (matrix[thatHand + i] != slave_matrix[i]) {
                    matrix[thatHand + i] = slave_matrix[i];
                    changed              = true;
                }
            }
        }

        matrix_scan_quantum();
    } else {
        transport_slave(matrix + thatHand, matrix + thisHand);

        matrix_slave_scan_user();
    }

    return changed;
}

uint8_t matrix_scan(void) {
    bool local_changed = false;

    // Set row, read cols
    for (uint8_t current_row = 0; current_row < ROWS_PER_HAND; current_row++) {
        local_changed |= read_cols_on_row(raw_matrix, current_row);
    }

    debounce(raw_matrix, matrix + thisHand, ROWS_PER_HAND, local_changed);

    bool remote_changed = matrix_post_scan();
    return (uint8_t)(local_changed || remote_changed);
}

matrix_row_t matrix_get_row(uint8_t row) {
    // TODO: return the requested row data
    return matrix[row];
}

void matrix_print(void) {
    // TODO: use print() to dump the current matrix state to console
}

__attribute__((weak)) void matrix_init_kb(void) { matrix_init_user(); }

__attribute__((weak)) void matrix_scan_kb(void) { matrix_scan_user(); }

__attribute__((weak)) void matrix_init_user(void) {}

__attribute__((weak)) void matrix_scan_user(void) {}
