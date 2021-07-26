#pragma once
#include QMK_KEYBOARD_H

#define HOME_A LCTL_T(KC_A)
#define HOME_S LSFT_T(KC_S)
#define HOME_D LSFT_T(KC_D)
#define HOME_F LT(_NUMPAD, KC_F)
#define HOME_K LCTL_T(KC_K)
#define HOME_O LSFT_T(KC_O)
#define HOME_U LT(_NUMPAD, KC_U)
#define HOME_T LCTL_T(KC_T)

#define NUM_CTRL LM(_NUMPAD, MOD_LCTL)
#define NUM_ALT LM(_NUMPAD, MOD_LALT)
#define SFT_SPACE LSFT_T(KC_SPACE)
#define SFT_BSPC LSFT_T(KC_BSPC)
#define SYM_ENT LT(_SYMBOL, KC_ENT)
#define NAV_ENT LT(_NAV, KC_ENT)
#define SYM_LEFT LT(_SYMBOL, KC_LEFT)

// Oneshot keys
#define OS_CTRL OSM(MOD_LCTL)
#define OS_SHFT OSM(MOD_LSFT)
#define OS_ALT OSM(MOD_LALT)
#define OS_GUI OSM(MOD_LGUI)

#define HY_S_CAPS TD(TD_S_CAPS)

#define ENC_TG TG(_ENC_SCROLL)

enum tap_dance_codes {
    TD_S_CAPS,
};

enum cusom_keys {
    ENC_SWITCH = SAFE_RANGE,
    NAV_TAB,
    KC_ATAB,
};
