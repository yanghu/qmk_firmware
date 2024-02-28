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
#include "quantum.h"
#include "quantum_keycodes.h"
#include "os_detection.h"
#include "users/yanghu/layers.h"
#include "users/yanghu/wrappers.h"
#include "yanghu.h"
#include QMK_KEYBOARD_H

#define LAYOUT_wrapper(...)            LAYOUT_planck_1x2uR(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_wrapper(
      __________QWERTY_L1__________, __________QWERTY_R1__________,
      __________QWERTY_L2__________, __________QWERTY_R2__________,
      __________QWERTY_L3__________, __________QWERTY_R3__________,
      DF(_GAME),    KC_LGUI, KC_LALT, KC_LGUI, MO(_SYMBOL), NAV_ENT, SFT_SPACE, OPT_LEFT, KC_DOWN, KC_UP,   LT(_PSCR, KC_RGHT)),

  [_BASE_MAC] = LAYOUT_wrapper(
      __________QWERTY_L1__________, __________QWERTY_R1__________,
      __________QWERTY_L2__________, __________QWERTY_R2__________,
      __________QWERTY_L3__________, __________QWERTY_R3__________,
      ENC_SWITCH,    KC_LGUI, KC_LALT, KC_LGUI, MO(_SYMBOL_MAC), NAV_ENT, SFT_SPACE,   OPT_LEFT, KC_DOWN, KC_UP,   LT(_PSCR, KC_RGHT)),

  [_GAME] = LAYOUT_wrapper(
      __________GAME_L1__________, __________GAME_R1__________,
      __________GAME_L2__________, __________GAME_R2__________,
      __________GAME_L3__________, __________GAME_R3__________,
      DF(_BASE),  KC_1, KC_2, KC_3, KC_4, KC_5, KC_SPACE, KC_LEFT, KC_DOWN, KC_UP,  KC_RIGHT),

  [_BASE_SIMPLE] = LAYOUT_wrapper(
      __________QWERTY_L1__________, __________QWERTY_R1__________,
      __________QWERTY_SIMPLE_L2__________, __________QWERTY_SIMPLE_R2__________,
      __________QWERTY_L3__________, __________QWERTY_R3__________,
      DF(_BASE),    KC_LGUI, KC_LALT, KC_LGUI, MO(_SYMBOL_MAC), NAV_ENT, KC_SPACE,   OPT_LEFT, KC_DOWN, KC_UP,   LT(_PSCR, KC_RGHT)),


  [_SYMBOL] = LAYOUT_wrapper(
      __________SYMBOL_L1__________,  __________SYMBOL_R1__________,
      __________SYMBOL_L2__________,  __________SYMBOL_R2__________,
      __________SYMBOL_L3__________,  __________SYMBOL_R3__________,
      _______, DF(_BASE_MAC), _______, _______, _______,  _______,KC_0      ,KC_LALT, _______, _______, _______),

  [_SYMBOL_MAC] = LAYOUT_wrapper(
      __________SYMBOL_L1_MAC______,  __________SYMBOL_R1_MAC______,
      __________SYMBOL_L2_MAC______,  __________SYMBOL_R2__________,
      __________SYMBOL_L3_MAC______,  __________SYMBOL_R3__________,
     _______, DF(_BASE), _______, KC_LALT ,_______, _______, G(KC_SPACE) ,KC_LALT, _______, _______, _______),

  [_NAV] = LAYOUT_wrapper(
      __________NAV_MAC_L1__________, __________NAV_R1__________,
      __________NAV_MAC_L2__________, __________NAV_R2__________, 
      __________BLANK__________, __________NAV_R3__________,
      _______, _______,_______, _______, G(KC_LALT), _______, KC_LSHIFT, KC_LALT, _______, _______, _______),

  [_NUMPAD] = LAYOUT_wrapper(
      __________NUM_L1__________, __________NUM_R1__________,
      __________NUM_L2__________, __________NUM_R2__________,
      __________NUM_L3__________, __________NUM_R3__________,
      __________BLANK__________,  KC_0, KC_P0, KC_DOT, KC_PENT, KC_PENT),

  [_FUNC] = LAYOUT_wrapper(
      __________FUNC_L1__________, __________FUNC_R1__________,
      __________FUNC_L2__________, __________BLANK__________,
      __________BLANK__________, __________BLANK__________,
      __________BLANK__________ ,RESET, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY),

  [_LAYER_SEL] = LAYOUT_wrapper(
      __________LAYER_SEL_L1__________, __________BLANK__________,
      __________BLANK__________, __________BLANK__________,
      __________BLANK__________, __________BLANK__________,
      __________BLANK__________, __________BLANK5__________),

  [_DEBUG_LAYER] = LAYOUT_wrapper(
      __________DEBUG_L1__________, __________BLANK__________,
      __________BLANK__________, __________BLANK__________,
      __________BLANK__________, __________BLANK__________,
      __________BLANK__________, __________BLANK5__________),

  [_PSCR] = LAYOUT_wrapper(
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, LCTL(KC_PSCR),
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, LALT(KC_PSCR),
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PSCR,
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX         , XXXXXXX, XXXXXXX, XXXXXXX, _______),

  [_ENC_SCROLL] = LAYOUT_wrapper(
      __________BLANK__________, __________BLANK__________,
      __________BLANK__________, __________BLANK__________,
      __________BLANK__________, __________BLANK__________,
      ENC_SWITCH, __________BLANK5__________, __________BLANK5__________),

  [_ENC_VIM] = LAYOUT_wrapper(
      __________BLANK__________, __________BLANK__________,
      __________BLANK__________, __________BLANK__________,
      __________BLANK__________, __________BLANK__________,
      ENC_SWITCH, __________BLANK5__________, __________BLANK5__________)
};

void encoder_update_user(uint8_t index, bool clockwise) {
      if (clockwise) {
        /* tap_code16(C(KC_RGHT)); */
        tap_code_delay(KC_VOLU, 10);
      } else {
        tap_code_delay(KC_VOLD, 10);
        /* tap_code16(C(KC_LEFT)); */
      }
      return;

  switch(get_highest_layer(layer_state)){
    case _BASE:
    case _BASE_MAC:
    case _BASE_SIMPLE:
    case _GAME:
      if (clockwise) {
        /* tap_code16(C(KC_RGHT)); */
        tap_code16(KC_VOLU);
      } else {
        tap_code16(KC_VOLD);
        /* tap_code16(C(KC_LEFT)); */
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
      }
      else {
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
      }
      else {
        tap_code16(C(KC_E));
      }
    break;
}
}


// RGB lightening

const rgblight_segment_t PROGMEM base_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 9, 0, 0, 0});
const rgblight_segment_t PROGMEM mac_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 8, HSV_GREEN});
const rgblight_segment_t PROGMEM adjust_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 8, HSV_RED});
const rgblight_segment_t PROGMEM nav_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 8, HSV_GREEN});
const rgblight_segment_t PROGMEM numpad_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 8, HSV_BLUE});
const rgblight_segment_t PROGMEM capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS({3, 4, HSV_WHITE});
const rgblight_segment_t PROGMEM enc_scroll_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 8, HSV_YELLOW});

// Now define the array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM rgb_layers[] = RGBLIGHT_LAYERS_LIST(
  base_layer,
  numpad_layer,
  nav_layer,
  enc_scroll_layer,
  capslock_layer,
  adjust_layer,
  mac_layer
  );

void keyboard_post_init_user(void) {
  // Enable the LED layers
  rgblight_layers = rgb_layers;
  // rgblight_set_layer_state(0, true);
  // Set default layer based on OS
  os_variant_t os = detected_host_os();
  switch(os) {
    case OS_MACOS:
      layer_move(_BASE_MAC);
  }

}


layer_state_t layer_state_set_keymap(layer_state_t state) {
  // Set RBG layer according to active keymap layer.
  rgblight_set_layer_state(0, layer_state_cmp(state, _BASE));
  rgblight_set_layer_state(1, layer_state_cmp(state, _NUMPAD));
  rgblight_set_layer_state(2, layer_state_cmp(state, _NAV));
  rgblight_set_layer_state(3, layer_state_cmp(state, _ENC_SCROLL));
  rgblight_set_layer_state(5, layer_state_cmp(state, _DEBUG_LAYER));
  rgblight_set_layer_state(5, layer_state_cmp(state, _ENC_VIM));
  rgblight_set_layer_state(6, layer_state_cmp(state, _BASE_MAC));
  rgblight_set_layer_state(6, layer_state_cmp(state, _SYMBOL_MAC));
  return state;
}


// I need some customized behaviors of mod tap keys:
// Left S shift: immediate trigger shift: (;, i?)
// Right K ctrl: immediate trigger: w, a(also, not check A's holding mode in this case)
// Left A ctrl: immediate trigger: o(ctrl-o in vim), j,k( for vim autocompletion)
// Space shift: immedage trigger shift: enter, tab.

bool process_record_keymap(uint16_t keycode, keyrecord_t *record){
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
  } // switch
  return true;
}
