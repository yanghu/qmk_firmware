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

#include QMK_KEYBOARD_H
#include "muse.h"

enum planck_layers {
    _BASE,
    _SYMBOL,
    _NAV,
    _NUMPAD,
    _FUNC,
    _DEBUG_LAYER,
    _PSCR,
    _ENC_SCROLL,
};

enum tap_dance_codes {
    TD_SFT_CAPS,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_planck_1x2uR(
      KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC,
      LCTL_T(KC_ESC), LCTL_T(KC_A), KC_S, KC_D, LT(_NUMPAD, KC_F), KC_G, KC_H, KC_J, LCTL_T(KC_K), KC_L, KC_SCLN, KC_QUOT,
      TD(TD_SFT_CAPS), KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, RSFT_T(KC_ENT),
      TO(_ENC_SCROLL), KC_LGUI, KC_LALT, LM(_NUMPAD, MOD_LALT), LT(_SYMBOL, KC_ENT), MO(_NAV), LSFT_T(KC_SPACE), KC_LEFT, KC_DOWN, KC_UP, LT(_PSCR, KC_RGHT)),

	[_SYMBOL] = LAYOUT_planck_1x2uR(
      KC_TILD, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSLS,
      KC_TRNS, KC_GRV, KC_LBRC, KC_LCBR, KC_EQL, KC_PLUS, KC_UNDS, KC_MINS, KC_RCBR, KC_RBRC, KC_COLN, KC_DQUO,
      KC_TRNS, KC_NO, KC_NO, KC_NO, KC_PIPE, KC_NO, KC_NO, KC_NO, KC_LT, KC_GT, KC_QUES, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  MO(_FUNC), KC_TRNS, KC_LALT, KC_TRNS, KC_TRNS, KC_TRNS),

	[_NAV] = LAYOUT_planck_1x2uR(
      KC_TRNS, KC_NO, LCTL(KC_RGHT), KC_NO, KC_NO, KC_NO, KC_HOME, KC_PGUP, KC_END, KC_NO, KC_NO, KC_NO,
      KC_NO, KC_NO, KC_LSFT, KC_PGDN, KC_NO, KC_NO, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_NO, KC_NO,
      KC_TRNS, KC_NO, KC_NO, KC_NO, KC_LCTL, LCTL(KC_LEFT), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS,
      KC_TRNS, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_LSFT, KC_NO, KC_NO, KC_NO, KC_NO),

	[_NUMPAD] = LAYOUT_planck_1x2uR(
      KC_TAB, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_PPLS, KC_PMNS,
      KC_LCTL, KC_LCTL, KC_LSFT, KC_NO, KC_NO, KC_NO, KC_NO, KC_4, KC_5, KC_6, KC_PAST, KC_PSLS,
      KC_LSFT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_1, KC_2, KC_3, KC_PEQL, KC_PEQL,
      KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_P0, KC_P0, KC_DOT, KC_PENT, KC_PENT),

	[_FUNC] = LAYOUT_planck_1x2uR(
      KC_GRV, RESET, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, TO(_DEBUG_LAYER),
      KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_MINS, KC_EQL, KC_LBRC, KC_TRNS, KC_BSLS, KC_TRNS,
      KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_NUHS, KC_NUBS, KC_PGUP, KC_PGDN, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY),

	[_DEBUG_LAYER] = LAYOUT_planck_1x2uR(
      KC_TRNS, RESET, DEBUG, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, TO(_BASE),
      KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
      KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, BL_TOGG, BL_STEP, BL_BRTG, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

	[_PSCR] = LAYOUT_planck_1x2uR(
       KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, LCTL(KC_PSCR),
       KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, LALT(KC_PSCR),
       KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_PSCR,
      KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS),

	[_ENC_SCROLL] = LAYOUT_planck_1x2uR(
      _______, _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,
      _______, _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,
      _______, _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,
      TO(_BASE), _______,_______,_______,_______,_______,_______,_______,_______,_______,_______)
};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LSFT_T(KC_SPACE):
            return TAPPING_TERM - 40;
        case LT(1, KC_ENT):
            return TAPPING_TERM - 50;
        default:
            return TAPPING_TERM;
    }
}

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(1, KC_ENT):
            return true;
        default:
            return false;
    }
}

bool get_retro_tapping(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LSFT_T(KC_SPACE):
            return false;
        case LT(1,KC_ENT):
            return false;
        case LCTL_T(KC_A):
            return false;
        default:
            return false;
    }
}

void encoder_update_user(uint8_t index, bool clockwise) {
   switch(get_highest_layer(layer_state)){
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
    }
    else {
        #ifdef MOUSEKEY_ENABLE
            tap_code(KC_MS_WH_UP);
        #else
            tap_code(KC_PGUP);
        #endif
    }
   }
}


// RGB lightening

const rgblight_segment_t PROGMEM base_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 9, 0, 0, 0});
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
    adjust_layer
);

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = rgb_layers;
    // rgblight_set_layer_state(0, true);
}

bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(4, led_state.caps_lock);
    return true;
}


layer_state_t layer_state_set_user(layer_state_t state) {
    // Set RBG layer according to active keymap layer.
    rgblight_set_layer_state(0, layer_state_cmp(state, _BASE));
    rgblight_set_layer_state(1, layer_state_cmp(state, _NUMPAD));
    rgblight_set_layer_state(2, layer_state_cmp(state, _NAV));
    rgblight_set_layer_state(3, layer_state_cmp(state, _ENC_SCROLL));
    rgblight_set_layer_state(5, layer_state_cmp(state, _DEBUG_LAYER));
    return state;
}

// Tap dance

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_SFT_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS),
};
