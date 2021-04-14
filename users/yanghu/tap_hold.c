#include QMK_KEYBOARD_H
#include "keycodes.h"
#include "layers.h"

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case SFT_SPACE:
      return TAPPING_TERM - 20;
    case HOME_F:
      return TAPPING_TERM - 40;
    case HOME_S:
    case HOME_D:
    case HOME_A:
		case SFT_BSPC:
      return TAPPING_TERM + 50;
    default:
      return TAPPING_TERM;
  }
}

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case HOME_S:
    case NAV_ENT:
    case SFT_SPACE:
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
    case SFT_BSPC:
      return false;
    default:
      return true;
  }
}

bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case OSL(_CAD_NUM):
        case TT(_CAD_NUM):
            return false;
        default:
            return true;
    }
}

// Tap dance
qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_S_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS),
};
