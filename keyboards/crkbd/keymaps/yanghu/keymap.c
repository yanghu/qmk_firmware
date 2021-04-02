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
#include "quantum.h"
#include "quantum_keycodes.h"
#include "yanghu.h"
#include QMK_KEYBOARD_H

#define LAYOUT_wrapper(...)            LAYOUT(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_wrapper(
      __________QWERTY_L1__________, __________QWERTY_R1__________,
      __________QWERTY_L2__________, __________QWERTY_R2__________,
      __________QWERTY_L3__________, __________QWERTY_R3__________,
        NUM_ALT, MO(_SYMBOL), NAV_ENT,  KC_SPACE,  SFT_SPACE, SYM_LEFT),

  [_SYMBOL] = LAYOUT_wrapper(
      __________SYMBOL_L1__________,  __________SYMBOL_R1__________,
      __________SYMBOL_L2__________,  __________SYMBOL_R2__________,
      __________SYMBOL_L3__________,  __________SYMBOL_R3__________,
      _______, _______, S(KC_ENT),  _______,  KC_0 ,KC_LALT),

  [_NAV] = LAYOUT_wrapper(
      __________NOKEY_________, __________NAV_R1__________,
      __________NAV_L2__________, __________NAV_R2__________, 
      _______, __________NOKEY5_________, __________NOKEY5_________, _______,
      __________BLANK__________),

  [_NUMPAD] = LAYOUT_wrapper(
      __________NUM_L1__________, __________NUM_R1__________,
      __________NUM_L2__________, __________NUM_R2__________,
      __________NUM_L3__________, __________NUM_R3__________,
      _______, _______, _______,  KC_PENT, KC_P0, KC_DOT),

  [_FUNC] = LAYOUT_wrapper(
      __________FUNC_L1__________, __________FUNC_R1__________,
      __________FUNC_L2__________, __________BLANK__________,
      __________BLANK__________, __________BLANK__________,
      __________BLANK__________),

  [_DEBUG_LAYER] = LAYOUT_wrapper(
      __________DEBUG_L1__________, __________BLANK__________,
      __________BLANK__________, __________BLANK__________,
      __________BLANK__________, __________BLANK__________,
      __________BLANK__________)
};

bool process_record_keymap(uint16_t keycode, keyrecord_t *record){
  switch (keycode) {
  } // switch
  return true;
}
