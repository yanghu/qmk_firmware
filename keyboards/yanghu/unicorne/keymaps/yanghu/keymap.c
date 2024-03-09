#include "action_layer.h"
#include "config.h"
#include "keycode.h"
#include "quantum.h"
#include "quantum_keycodes.h"
#include "rgblight_list.h"
#include "users/yanghu/layers.h"
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
      ENC_SWITCH, KC_LSHIFT, MO(_SYMBOL), NAV_ENT, 
      SFT_BSPC, KC_SPACE, KC_LCTRL, ENC_SWITCH),

  [_SYMBOL] = LAYOUT_wrapper(
      __________SYMBOL_L1__________,  __________SYMBOL_R1__________,
      __________SYMBOL_L2__________,  __________SYMBOL_R2__________,
      __________SYMBOL_L3__________,  __________SYMBOL_R3__________,
      _______, _______, _______, _______,  
      _______, KC_0, _______, _______),

  [_NAV] = LAYOUT_wrapper(
      __________NAV_L1__________, __________NAV_R1__________,
      __________NAV_L2__________, __________NAV_R2__________, 
      _______, __________NOKEY5__________, __________NOKEY5__________, _______,
      __________BLANK__________, _______, _______),

  [_NUMPAD] = LAYOUT_wrapper(
      __________NUM_L1__________, __________NUM_R1__________,
      __________NUM_L2__________, __________NUM_R2__________,
      __________NUM_L3__________, __________NUM_R3__________,
      _______, _______, _______, _______, KC_PENT, KC_0, KC_DOT, _______),

  [_FUNC] = LAYOUT_wrapper(
      __________FUNC_L1__________, __________FUNC_R1__________,
      __________FUNC_L2__________, __________BLANK__________,
      __________FUNC_L3__________, __________FUNC_R3__________,
      __________BLANK__________, _______, _______),

  [_CAD] = LAYOUT_wrapper(
      __________CAD_L1__________, __________CAD_R1__________,
      __________CAD_L2__________, __________CAD_R2__________,
      __________CAD_L3__________, __________CAD_R3__________,
      _______, __________CAD_L4__________, __________CAD_R4__________, _______),

  [_CAD_NUM] = LAYOUT_wrapper(
      __________CAD_NUM_L1__________, __________BLANK__________,
      __________CAD_NUM_L2__________, __________BLANK__________,
      __________CAD_NUM_L3__________, __________BLANK__________,
      _______, __________CAD_NUM_L4__________, _______, _______, _______, _______),

  [_LAYER_SEL] = LAYOUT_wrapper(
      __________LAYER_SEL_L1__________, __________BLANK__________,
      __________LAYER_SEL_L2__________, __________BLANK__________,
      __________BLANK__________, __________BLANK__________,
      __________BLANK__________, _______, _______),

  [_DEBUG_LAYER] = LAYOUT_wrapper(
      __________DEBUG_L1__________, __________BLANK__________,
      __________BLANK__________, __________BLANK__________,
      __________BLANK__________, __________BLANK__________,
      __________BLANK__________, _______, _______),

  [_PSCR] = LAYOUT_wrapper(
      __________NOKEY__________, __________NOKEY5__________, LALT(KC_PSCR),
      __________NOKEY__________, __________NOKEY5__________, KC_PSCR,
      __________BLANK__________, __________BLANK__________,
      __________BLANK__________, _______, _______),

  [_ENC_SCROLL] = LAYOUT_wrapper(
      __________BLANK__________, __________BLANK__________,
      __________BLANK__________, __________BLANK__________,
      __________BLANK__________, __________BLANK__________,
      ENC_SWITCH, __________BLANK5__________, _______, _______),

  [_ENC_VIM] = LAYOUT_wrapper(
      __________BLANK__________, __________BLANK__________,
      __________BLANK__________, __________BLANK__________,
      __________BLANK__________, __________BLANK__________,
      ENC_SWITCH, __________BLANK5__________, _______, _______)
};

// clang-format on

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        switch (get_highest_layer(layer_state)) {
            case _BASE:
                if (clockwise) {
                    tap_code16(C(KC_RGHT));
                } else {
                    tap_code16(C(KC_LEFT));
                }
                break;
            case _ENC_SCROLL:
                // Somehow my encoder direction is reversed
                if (clockwise) {
#ifdef MOUSEKEY_ENABLE
                    tap_code(KC_MS_WH_DOWN);
#else
                    tap_code(KC_PGDN);
#endif
                } else {
#ifdef MOUSEKEY_ENABLE
                    tap_code(KC_MS_WH_UP);
#else
                    tap_code(KC_PGUP);
#endif
                }
                break;
            case _ENC_VIM:
                // Somehow my encoder direction is reversed
                if (clockwise) {
                    tap_code16(C(KC_Y));
                } else {
                    tap_code16(C(KC_E));
                }
                break;
        }     // switch
    } else {  // index = 1: right encoder
        switch (get_highest_layer(layer_state)) {
            case _BASE:
                if (clockwise) {
                    rgblight_increase_hue_noeeprom();
                } else {
                    rgblight_decrease_hue_noeeprom();
                }
                break;
            case _ENC_SCROLL:
                if (clockwise) {
                    rgblight_step();
                } else {
                    rgblight_step_reverse();
                }
                break;
            case _ENC_VIM:
                if (clockwise) {
                    rgblight_increase_val();
                } else {
                    rgblight_decrease_val();
                }
                break;
        }
    }
}

bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case ENC_SWITCH:
            if (record->event.pressed) {
                // Toggle encoder layers based on current layer.
                if (IS_LAYER_ON(_ENC_VIM)) {
                    // Back to base if at vim layer.
                    layer_off(_ENC_SCROLL);
                    layer_off(_ENC_VIM);
                } else if (IS_LAYER_ON(_ENC_SCROLL)) {
                    // if scroll layer is on, turn on vim layer.
                    layer_on(_ENC_VIM);
                } else {
                    layer_on(_ENC_SCROLL);
                }
                return false;
            }
    }  // switch
    return true;
}

#ifdef OLED_ENABLE
void oled_task_user(void) {
    /* oled_render_keylog(); */
    oled_render_layer();
    oled_render_mods();
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    /* if (!is_master) { */
    /* return OLED_ROTATION_90;  // flips the display 180 degrees if offhand */
    /* } */
    return OLED_ROTATION_270;
}
#endif

#ifdef RGBLIGHT_LAYERS
// RGB lightening

const rgblight_segment_t PROGMEM base_layer[]       = RGBLIGHT_LAYER_SEGMENTS({0, 8, 0, 0, 0});
const rgblight_segment_t PROGMEM adjust_layer[]     = RGBLIGHT_LAYER_SEGMENTS({0, 8, HSV_RED});
const rgblight_segment_t PROGMEM symbol_layer[]     = RGBLIGHT_LAYER_SEGMENTS({0, 8, HSV_PURPLE});
const rgblight_segment_t PROGMEM nav_layer[]        = RGBLIGHT_LAYER_SEGMENTS({0, 8, HSV_GREEN});
const rgblight_segment_t PROGMEM numpad_layer[]     = RGBLIGHT_LAYER_SEGMENTS({0, 8, HSV_BLUE});
const rgblight_segment_t PROGMEM capslock_layer[]   = RGBLIGHT_LAYER_SEGMENTS({6, 7, HSV_WHITE});
const rgblight_segment_t PROGMEM enc_scroll_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 8, HSV_YELLOW});

// Now define the array of layers. Later layers take precedence
// clang-format off
const rgblight_segment_t *const PROGMEM rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    base_layer,
    symbol_layer,
    numpad_layer,
    nav_layer,
    enc_scroll_layer,
    capslock_layer,
    adjust_layer);
// clang-format on

layer_state_t layer_state_set_keymap(layer_state_t state) {
    // Set RBG layer according to active keymap layer.
    rgblight_set_layer_state(0, layer_state_cmp(state, _BASE));
    rgblight_set_layer_state(1, layer_state_cmp(state, _SYMBOL));
    rgblight_set_layer_state(2, layer_state_cmp(state, _NUMPAD));
    rgblight_set_layer_state(3, layer_state_cmp(state, _NAV));
    rgblight_set_layer_state(4, layer_state_cmp(state, _ENC_SCROLL));
    rgblight_set_layer_state(6, layer_state_cmp(state, _DEBUG_LAYER));
    rgblight_set_layer_state(6, layer_state_cmp(state, _ENC_VIM));
    return state;
}

#endif

void keyboard_post_init_user(void) {
    rgblight_sethsv(HSV_BLUE);
#ifdef RGBLIGHT_LAYERS
    rgblight_layers = rgb_layers;
#endif
}
