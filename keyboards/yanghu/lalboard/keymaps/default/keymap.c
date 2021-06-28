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
#include QMK_KEYBOARD_H

enum layer {
    _BASE,
    _LOWER,
    _UPPER,
    _NAV,
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_lalboard_alt(
      // Down
      KC_A, KC_O, KC_E, KC_U,  KC_H, KC_T, KC_N, KC_S,
      // North
      KC_SLASH, KC_COMMA, KC_DOT, KC_Q, KC_M, KC_W, KC_V, KC_Z,
      KC_LPRN, KC_X, KC_Y, KC_I, KC_QUOTE, KC_GRAVE, XXXXXXX, KC_BSLASH,
      KC_SCOLON, KC_P, KC_J, KC_K, KC_G, KC_C, KC_R, KC_L,
      KC_DELETE, KC_ESC, XXXXXXX, KC_DQUO, KC_D, KC_F, KC_B, KC_RPRN,

      /*     Inner, Down, Mode,  Upper-Out, Lower-Out,  */
      /*LT*/ KC_ENTER, KC_LSHIFT, MO(_LOWER), KC_TAB, KC_LCTRL,
      /*RT*/ KC_SPACE, MO(_UPPER), MO(_NAV), KC_BSPC, KC_LALT
  ),
};
// clang-format on
