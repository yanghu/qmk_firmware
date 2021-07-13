/* Copyright 2021 Yang Hu
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

#include "keycode.h"
#include "users/yanghu/wrappers.h"
#include "yanghu.h"
#include QMK_KEYBOARD_H

#define LAYOUT_wrapper(...) LAYOUT_lalboard_alt(__VA_ARGS__)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_wrapper(
      // Down
      KC_A, KC_O, KC_E, KC_U,  KC_H, KC_T, KC_N, KC_S,
      // North
      KC_DELETE, XXXXXXX, KC_COMMA, KC_Q, KC_M, KC_W, KC_V, KC_Z,
      // East
      KC_LPRN, KC_X, KC_Y, KC_I, KC_QUOTE, KC_DOT, KC_GRAVE, KC_RPRN,
      // South
      KC_SCOLON, KC_K, KC_J, KC_P, KC_G, KC_C, KC_R, KC_L,
      // West
      KC_SLASH, KC_TAB, KC_ESC, KC_DQUO, KC_D, KC_F, KC_B, KC_BSPC,
      /*     Inner,    Down,       Mode,       Upper-Out, Lower-Out,  */
      /*LT*/ KC_ENTER, MO(_SYMBOL), MO(_LALNUM), KC_LSFT,    KC_LCTRL,
      /*RT*/ KC_SPACE, KC_LSHIFT,  MO(_NAV),   KC_BSPC,   KC_LALT
  ),

  [_LALNUM] = LAYOUT_wrapper(
      // Down
      KC_ATAB, KC_LSFT, G(KC_SPACE), C(KC_SPACE),  KC_4, KC_5, KC_6, KC_0,
      // North
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      // East
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, C(KC_CIRC), XXXXXXX, XXXXXXX, KC_MINUS,
      // South
      C(KC_A), C(KC_X), C(KC_C), C(KC_V), KC_1, KC_2, KC_3, KC_DOT,
      A(KC_1), A(KC_2), A(KC_3), A(KC_4), KC_7, KC_8, KC_9, KC_PLUS,
      /*     Inner,    Down,       Mode,       Upper-Out, Lower-Out,  */
      /*LT*/ __________BLANK5__________,
      /*RT*/ __________BLANK5__________
  ),

  [_SYMBOL] = LAYOUT_wrapper(
      // Down
      KC_EXLM, KC_AT, KC_HASH, KC_DOLLAR,  KC_AMPR, KC_ASTR, XXXXXXX, KC_QUES,
      // North
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      // East
      XXXXXXX, KC_LBRC, KC_LCBR, KC_PERC, XXXXXXX, KC_GT, XXXXXXX, XXXXXXX,
      // South
      KC_PIPE, KC_GRAVE, KC_BSLASH, KC_TILD, KC_MINUS, KC_EQL, KC_UNDS, KC_PLUS,
      // West
      XXXXXXX, XXXXXXX, KC_LT, XXXXXXX, KC_CIRC, KC_RCBR, KC_RBRC, XXXXXXX,
      /*     Inner,    Down,       Mode,       Upper-Out, Lower-Out,  */
      /*LT*/ __________BLANK5__________,
      /*RT*/ __________BLANK5__________
  ),

  [_NAV] = LAYOUT_wrapper(
      // Down
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PGUP, XXXXXXX, KC_PGDOWN, XXXXXXX,
      // North
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      // East
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      // South
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_DOWN, KC_UP,   KC_RIGHT, XXXXXXX,
      // West
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LEFT, XXXXXXX, XXXXXXX, XXXXXXX,
      /*     Inner,    Down,       Mode,       Upper-Out, Lower-Out,  */
      /*LT*/ __________BLANK5__________,
      /*RT*/ __________BLANK5__________
  ),
};
// clang-format on

bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {}  // switch
    return true;
}
