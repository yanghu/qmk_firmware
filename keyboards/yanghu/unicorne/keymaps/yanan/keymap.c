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

#include "action_layer.h"
#include "config.h"
#include "keycode.h"
#include "keycodes.h"
#include "quantum.h"
#include "quantum_keycodes.h"
#include "rgblight_list.h"
#include "users/yanghu/layers.h"
#include "users/yanghu/wrappers.h"
#include "yanghu.h"
#include QMK_KEYBOARD_H

#define LAYOUT_wrapper(...) LAYOUT(__VA_ARGS__)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_wrapper(
      __________QWERTY_L1__________, __________QWERTY_R1__________,
      __________QWERTY_L2__________, __________QWERTY_R2__________,
      __________QWERTY_L3__________, __________QWERTY_R3__________,
      KC_ESCAPE,  KC_LGUI, MO(_SYMBOL), NAV_ENT, 
      KC_SPACE,   SFT_BSPC, KC_LCTRL, ENC_SWITCH),

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
      ENC_SWITCH, __________BLANK5__________, _______, _______)
};
// clang-format on
//
void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code16(C(KC_RGHT));
        } else {
            tap_code16(C(KC_LEFT));
        }
    } else {
        // Somehow my encoder direction is reversed
        if (clockwise) {
            tap_code(KC_MS_WH_DOWN);
        } else {
            tap_code(KC_MS_WH_UP);
        }
    }
}

// I need some customized behaviors of mod tap keys:
// Left S shift: immediate trigger shift: (;, i?)
// Right K ctrl: immediate trigger: w, a(also, not check A's holding mode in this case)
// Left A ctrl: immediate trigger: o(ctrl-o in vim), j,k( for vim autocompletion)
// Space shift: immedage trigger shift: enter, tab.

bool process_record_keymap(uint16_t keycode, keyrecord_t* record) {
    /* switch (keycode) { */
    /*     case ENC_SWITCH: */
    /*         if (record->event.pressed) { */
    /*             /1* // Toggle encoder layers based on current layer. *1/ */
    /*             /1* if (IS_LAYER_ON(_ENC_SCROLL)) { *1/ */
    /*             /1*     // Back to base if at vim layer. *1/ */
    /*             /1*     layer_off(_ENC_SCROLL); *1/ */
    /*             /1* } else { *1/ */
    /*             /1*     layer_on(_ENC_SCROLL); *1/ */
    /*             /1* } *1/ */
    /*             /1* return false; *1/ */
    /*         } */
    /* }  // switch */
    return true;
}

#ifdef OLED_DRIVER_ENABLE
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
