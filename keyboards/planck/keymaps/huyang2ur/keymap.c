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
};

#define HOME_A LCTL_T(KC_A)
#define HOME_S LSFT_T(KC_S)
#define HOME_F LT(_NUMPAD, KC_F)
#define HOME_K LCTL_T(KC_K)

#define NUM_CTRL LM(_NUMPAD, MOD_LCTL)
#define NUM_ALT LM(_NUMPAD, MOD_LALT)
#define SFT_SPACE LSFT_T(KC_SPACE)
#define SYM_ENT LT(_SYMBOL, KC_ENT)
#define SYM_LEFT LT(_SYMBOL, KC_LEFT)

#define HY_S_CAPS TD(TD_S_CAPS)

#define ENC_TG TG(_ENC_SCROLL)
enum tap_dance_codes {
    TD_S_CAPS,
};


// Combo:
enum combo_events {
  JL_ESC,
};

const uint16_t PROGMEM my_combo[] = {KC_J, KC_L, COMBO_END};
combo_t key_combos[COMBO_COUNT] = {[JL_ESC] = COMBO(my_combo, KC_ESC)};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_planck_1x2uR(
      KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,     KC_Y,   KC_U,   KC_I,     KC_O,    KC_P,    KC_BSPC,
      NUM_CTRL,  HOME_A,  HOME_S,  KC_D,    HOME_F,  KC_G,     KC_H,   KC_J,   HOME_K,   KC_L,    KC_SCLN, KC_QUOT,
      HY_S_CAPS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,     KC_N,   KC_M,   KC_COMM,  KC_DOT,  KC_SLSH, RSFT_T(KC_ENT),
      ENC_TG,    KC_LGUI, KC_LALT, NUM_ALT, SYM_ENT, MO(_NAV), SFT_SPACE,      SYM_LEFT, KC_DOWN, KC_UP,   LT(_PSCR, KC_RGHT)),

	[_SYMBOL] = LAYOUT_planck_1x2uR(
      KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,   KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
      KC_GRV,  KC_LBRC, KC_RBRC, KC_LCBR, KC_RCBR, _______,   _______, KC_MINS, KC_EQL,  KC_UNDS, KC_COLN, KC_DQUO,
      _______, KC_PIPE, XXXXXXX, KC_BSLS, KC_TILD, XXXXXXX,   XXXXXXX, KC_PLUS, KC_LT,   KC_GT,   KC_QUES, _______,
      _______, _______, _______, _______, _______, MO(_FUNC), _______,          KC_LALT, _______, _______, _______),

	[_NAV] = LAYOUT_planck_1x2uR(
      _______, XXXXXXX, C(KC_RGHT),XXXXXXX, XXXXXXX, XXXXXXX,    KC_HOME, KC_PGUP, KC_END, XXXXXXX, XXXXXXX, _______,
      XXXXXXX, XXXXXXX, KC_LSFT,   KC_PGDN, KC_LCTL, XXXXXXX,    KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, XXXXXXX, XXXXXXX,
      _______, XXXXXXX, XXXXXXX,   XXXXXXX, KC_LCTL, C(KC_LEFT), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
      _______, XXXXXXX, XXXXXXX,   _______, _______, _______,    KC_LSFT,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX),

	[_NUMPAD] = LAYOUT_planck_1x2uR(
      KC_TAB,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7, KC_8,  KC_9,   KC_PPLS, _______,
      KC_LCTL, KC_LCTL, KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_4, KC_5,  KC_6,   KC_PMNS, KC_PAST,
      KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_1, KC_2,  KC_3,   KC_PSLS, KC_PEQL,
      XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______, KC_P0,         KC_P0, KC_DOT, KC_PENT, KC_PENT),

	[_FUNC] = LAYOUT_planck_1x2uR(
      KC_GRV,  RESET,   KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, TO(_DEBUG_LAYER),
      _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, _______, KC_BSLS,
      _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NUHS, KC_NUBS, KC_PGUP, KC_PGDN, _______,
      _______, _______, _______, _______, _______, _______, _______         , KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY),

	[_DEBUG_LAYER] = LAYOUT_planck_1x2uR(
      _______, RESET,   DEBUG,   RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, TO(_BASE),
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______,
      _______, BL_TOGG, BL_STEP, BL_BRTG, _______, _______, _______         , _______, _______, _______, _______),

	[_PSCR] = LAYOUT_planck_1x2uR(
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, LCTL(KC_PSCR),
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, LALT(KC_PSCR),
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PSCR,
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX         , XXXXXXX, XXXXXXX, XXXXXXX, _______),

	[_ENC_SCROLL] = LAYOUT_planck_1x2uR(
      _______, _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,
      _______, _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,
      _______, _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,
      ENC_TG,  _______,_______,_______,_______,_______,_______        ,_______,_______,_______,_______)
};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LSFT_T(KC_SPACE):
        case LSFT_T(KC_S):
        case LT(_SYMBOL, KC_ENT):
            return TAPPING_TERM - 40;
        case LT(_SYMBOL, KC_LEFT):
            return TAPPING_TERM - 70;
        default:
            return TAPPING_TERM;
    }
}

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LSFT_T(KC_S):
            return true;
        default:
            return false;
    }
}

bool get_retro_tapping(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LSFT_T(KC_SPACE):
            return false;
        case LT(_SYMBOL, KC_ENT):
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
    [TD_S_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS),
};


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
    }

    }
    return true;
};
