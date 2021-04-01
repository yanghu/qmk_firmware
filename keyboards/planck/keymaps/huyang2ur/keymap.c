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
#include "quantum.h"
#include "quantum_keycodes.h"
#include "users/yanghu/wrappers.h"
#include "yanghu.h"
#include QMK_KEYBOARD_H

enum planck_layers {
  _BASE,
  _SYMBOL,
  _NAV,
  _NUMPAD,
  _FUNC,
  _DEBUG_LAYER,
  _PSCR,
  _ENC_SCROLL,
  _ENC_VIM,
};

/* #define HOME_A LCTL_T(KC_A) */
/* #define HOME_S LSFT_T(KC_S) */
/* #define HOME_F LT(_NUMPAD, KC_F) */
/* #define HOME_K LCTL_T(KC_K) */

#define NUM_CTRL LM(_NUMPAD, MOD_LCTL)
#define NUM_ALT LM(_NUMPAD, MOD_LALT)
#define SFT_SPACE LSFT_T(KC_SPACE)
#define SYM_ENT LT(_SYMBOL, KC_ENT)
#define NAV_ENT LT(_NAV, KC_ENT)
#define SYM_LEFT LT(_SYMBOL, KC_LEFT)

#define HY_S_CAPS TD(TD_S_CAPS)

#define ENC_TG TG(_ENC_SCROLL)
enum tap_dance_codes {
  TD_S_CAPS,
};

enum cusom_keys {
  ENC_SWITCH = SAFE_RANGE
};

// Combo:
enum combo_events {
  JL_ESC,
};

const uint16_t PROGMEM my_combo[] = {KC_J, KC_L, COMBO_END};
combo_t key_combos[COMBO_COUNT] = {[JL_ESC] = COMBO(my_combo, KC_ESC)};

#define LAYOUT_wrapper(...)            LAYOUT_planck_1x2uR(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_wrapper(
      __________QWERTY_L1__________, __________QWERTY_R1__________,
      __________QWERTY_L2__________, __________QWERTY_R2__________,
      __________QWERTY_L3__________, __________QWERTY_R3__________,
      ENC_SWITCH,    KC_LGUI, KC_LALT, NUM_ALT, MO(_SYMBOL), NAV_ENT, SFT_SPACE,   SYM_LEFT, KC_DOWN, KC_UP,   LT(_PSCR, KC_RGHT)),

  [_SYMBOL] = LAYOUT_wrapper(
      __________SYMBOL_L1__________,  __________SYMBOL_R1__________,
      __________SYMBOL_L2__________,  __________SYMBOL_R2__________,
      __________SYMBOL_L3__________,  __________SYMBOL_R3__________,
      __________BLANK5__________, S(KC_ENT),KC_0      ,KC_LALT, _______, _______, _______),

  [_NAV] = LAYOUT_wrapper(
      __________NOKEY_________, __________NAV_R1__________,
      __________NAV_L2__________, __________NAV_R2__________, 
      _______, __________NOKEY5_________, __________NOKEY5_________, _______,
      __________BLANK__________,                  __________BLANK5__________),

  [_NUMPAD] = LAYOUT_wrapper(
      __________NUM_L1__________, __________NUM_R1__________,
      __________NUM_L2__________, __________NUM_R2__________,
      __________NUM_L3__________, __________NUM_R3__________,
      __________BLANK__________,  KC_P0, KC_P0, KC_DOT, KC_PENT, KC_PENT),

  [_FUNC] = LAYOUT_wrapper(
      __________FUNC_L1__________, __________FUNC_R1__________,
      __________FUNC_L2__________, __________BLANK__________,
      __________BLANK__________, __________BLANK__________,
      __________BLANK__________ ,_______         , KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY),

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

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case SFT_SPACE:
    case HOME_S:
    case HOME_F:
      return TAPPING_TERM - 40;
    case SYM_LEFT:
      return TAPPING_TERM - 70;
    case HOME_A:
      return TAPPING_TERM + 10;
    default:
      return TAPPING_TERM;
  }
}

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case HOME_S:
      return true;
    default:
      return false;
  }
}

bool get_retro_tapping(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LSFT_T(KC_SPACE):
      return false;
    case LCTL_T(KC_A):
      return false;
    default:
      return false;
  }
}

bool get_ignore_mod_tap_interrupt(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case SFT_T(KC_SPC):
      return true;
    default:
      return true;
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
  rgblight_set_layer_state(5, layer_state_cmp(state, _ENC_VIM));
  return update_tri_layer_state(state, _NAV, _SYMBOL, _FUNC);
}

// Tap dance
qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_S_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS),
};


// I need some customized behaviors of mod tap keys:
// Left S shift: immediate trigger shift: (;, i?)
// Right K ctrl: immediate trigger: w, a(also, not check A's holding mode in this case)
// Left A ctrl: immediate trigger: o(ctrl-o in vim), j,k( for vim autocompletion)
// Space shift: immedage trigger shift: enter, tab.


// Initialize variable holding the binary
// representation of active modifiers.
uint8_t mod_state;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // Store the current modifier state in the variable for later reference
  mod_state = get_mods();
  switch (keycode) {
    case KC_BSPC:
      {
        // Initialize a boolean variable that keeps track
        // of the delete key status: registered or not?
        static bool delkey_registered;
        if (record->event.pressed) {
          // Detect the activation of either shift keys
          if (mod_state & MOD_MASK_SHIFT) {
            // First temporarily canceling both shifts so that
            // shift isn't applied to the KC_DEL keycode
            del_mods(MOD_MASK_SHIFT);
            register_code(KC_DEL);
            // Update the boolean variable to reflect the status of KC_DEL
            delkey_registered = true;
            // Reapplying modifier state so that the held shift key(s)
            // still work even after having tapped the Backspace/Delete key.
            set_mods(mod_state);
            return false;
          }
        } else { // on release of KC_BSPC
          // In case KC_DEL is still being sent even after the release of KC_BSPC
          if (delkey_registered) {
            unregister_code(KC_DEL);
            delkey_registered = false;
            return false;
          }
        }
        // Let QMK process the KC_BSPC keycode as usual outside of shift
        return true;
      } // case kc_bspc
    case ENC_SWITCH:
      {
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
  }
  return true;
};
