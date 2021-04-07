#include QMK_KEYBOARD_H

// Combo:
enum combo_events {
  JL_ESC,
  CV_TAB,
  SD_SHIFT,
};

const uint16_t PROGMEM jl_combo[] = {KC_J, KC_L, COMBO_END};
const uint16_t PROGMEM cv_combo[] = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM sd_combo[] = {KC_S, KC_D, COMBO_END};
combo_t key_combos[COMBO_COUNT] = {
  [JL_ESC] = COMBO(jl_combo, KC_ESC),
  [CV_TAB] = COMBO(cv_combo, KC_TAB),
  [SD_SHIFT] = COMBO(sd_combo, KC_LSHIFT),
};

