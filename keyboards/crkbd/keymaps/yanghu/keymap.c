/* Copyright 2015-2017 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

// TODO: add shift + backspace = delete
// TODO: add ctrl + symbols?

#include "config.h"
#include "keycode.h"
#include "layers.h"
#include "quantum.h"
#include "quantum_keycodes.h"
#include "users/yanghu/wrappers.h"
#include "yanghu.h"
#include QMK_KEYBOARD_H

#define LAYOUT_wrapper(...) LAYOUT(__VA_ARGS__)

void set_keylog(uint16_t keycode, keyrecord_t *record);

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_wrapper(
      __________QWERTY_L1__________, __________QWERTY_R1__________,
      __________QWERTY_L2__________, __________QWERTY_R2__________,
      __________QWERTY_L3__________, __________QWERTY_R3__________,
        KC_LSHIFT, MO(_SYMBOL), NAV_ENT, SFT_BSPC, KC_SPACE, KC_LCTRL),

  [_DVORAK_BASE] = LAYOUT_wrapper(
      __________DVORAK_L1__________, __________DVORAK_R1__________,
      __________DVORAK_L2__________, __________DVORAK_R2__________,
      __________DVORAK_L3__________, __________DVORAK_R3__________,
        KC_LSHIFT, MO(_SYMBOL), NAV_ENT, SFT_BSPC, KC_SPACE, KC_LCTRL),

  [_SYMBOL] = LAYOUT_wrapper(
      __________SYMBOL_L1__________,  __________SYMBOL_R1__________,
      __________SYMBOL_L2__________,  __________SYMBOL_R2__________,
      __________SYMBOL_L3__________,  __________SYMBOL_R3__________,
      _______, _______, _______, _______,  KC_0, _______),

  [_NAV] = LAYOUT_wrapper(
      __________NAV_L1__________, __________NAV_R1__________,
      __________NAV_L2__________, __________NAV_R2__________, 
      _______, __________NOKEY5__________, __________NOKEY5__________, _______,
      __________BLANK__________),

  [_NUMPAD] = LAYOUT_wrapper(
      __________NUM_L1__________, __________NUM_R1__________,
      __________NUM_L2__________, __________NUM_R2__________,
      __________NUM_L3__________, __________NUM_R3__________,
      _______, _______, _______, KC_PENT, KC_0, KC_DOT),

  [_FUNC] = LAYOUT_wrapper(
      __________FUNC_L1__________, __________FUNC_R1__________,
      __________FUNC_L2__________, __________BLANK__________,
      __________FUNC_L3__________, __________FUNC_R3__________,
      __________BLANK__________),

  [_CAD] = LAYOUT_wrapper(
      __________CAD_L1__________, __________CAD_R1__________,
      __________CAD_L2__________, __________CAD_R2__________,
      __________CAD_L3__________, __________CAD_R3__________,
      __________CAD_L4__________, __________CAD_R4__________),

  [_CAD_NUM] = LAYOUT_wrapper(
      __________CAD_NUM_L1__________, __________BLANK__________,
      __________CAD_NUM_L2__________, __________BLANK__________,
      __________CAD_NUM_L3__________, __________BLANK__________,
      __________CAD_NUM_L4__________, _______, _______, _______),

  [_LAYER_SEL] = LAYOUT_wrapper(
      __________LAYER_SEL_L1__________, __________BLANK__________,
      __________LAYER_SEL_L2__________, __________BLANK__________,
      __________BLANK__________, __________BLANK__________,
      __________BLANK__________),

  [_DEBUG_LAYER] = LAYOUT_wrapper(
      __________DEBUG_L1__________, __________BLANK__________,
      __________BLANK__________, __________BLANK__________,
      __________BLANK__________, __________BLANK__________,
      __________BLANK__________),

  [_PSCR] = LAYOUT_wrapper(
      __________NOKEY__________, __________NOKEY5__________, LALT(KC_PSCR),
      __________NOKEY__________, __________NOKEY5__________, KC_PSCR,
      __________BLANK__________, __________BLANK__________,
      __________BLANK__________),
};

// clang-format on

bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {}  // switch
#ifdef OLED_DRIVER_ENABLE
    if (record->event.pressed) {
        set_keylog(keycode, record);
    }
#endif
    return true;
}

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    /* if (!is_master) { */
    /* return OLED_ROTATION_90;  // flips the display 180 degrees if offhand */
    /* } */
    return OLED_ROTATION_270;
}

char keylog_str[24] = {};

const char code_to_name[60] = {' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', 'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\', '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
    char name = ' ';
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) || (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) {
        keycode = keycode & 0xFF;
    }
    if (keycode < 60) {
        name = code_to_name[keycode];
    }

    // update keylog
    snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c", record->event.key.row, record->event.key.col, keycode, name);
}

void oled_render_keylog(void) { oled_write(keylog_str, false); }

void render_bootmagic_status(bool status) {
    /* Show Ctrl-Gui Swap options */
    static const char PROGMEM logo[][2][3] = {
        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
    };
    if (status) {
        oled_write_ln_P(logo[0][0], false);
        oled_write_ln_P(logo[0][1], false);
    } else {
        oled_write_ln_P(logo[1][0], false);
        oled_write_ln_P(logo[1][1], false);
    }
}

void oled_task_user(void) {
    if (is_master) {
        /* oled_render_layer_state(); */
        /* oled_render_keylog(); */
        oled_render_layer();
        oled_render_mods();
    }
}

#endif  // OLED_DRIVER_ENABLE
