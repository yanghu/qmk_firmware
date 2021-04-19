#include QMK_KEYBOARD_H
#include "keycodes.h"
#include "layers.h"

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case SFT_SPACE:
    case HOME_K:
      return TAPPING_TERM - 20;
    case HOME_S:
    case HOME_F:
      return TAPPING_TERM - 40;
    case HOME_D:
      return TAPPING_TERM - 45;
    case SYM_LEFT:
      return TAPPING_TERM - 70;
    case HOME_A:
      return TAPPING_TERM + 10;
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
    case SFT_BSPC:
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
