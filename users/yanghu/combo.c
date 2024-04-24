#include "keycode.h"
#include "keycodes.h"
#include QMK_KEYBOARD_H

// Combo:
enum combo_events {
  COMBO_ESC,
  CV_TAB,
  SD_SHIFT,
};

const uint16_t PROGMEM esc_combo[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM lb_combo[] = {KC_M, KC_COMMA, COMBO_END};
const uint16_t PROGMEM rb_combo[] = {KC_DOT, KC_COMMA, COMBO_END};
const uint16_t PROGMEM cv_combo[] = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM sd_combo[] = {KC_S, KC_D, COMBO_END};
combo_t key_combos[COMBO_COUNT] = {
  [COMBO_ESC] = COMBO(esc_combo, KC_ESC),
  [CV_TAB] = COMBO(cv_combo, KC_TAB),
  [SD_SHIFT] = COMBO(sd_combo, KC_LSHIFT),
};

