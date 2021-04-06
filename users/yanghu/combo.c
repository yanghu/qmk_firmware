#include QMK_KEYBOARD_H

// Combo:
enum combo_events {
  JL_ESC,
  CV_TAB,
};

const uint16_t PROGMEM jl_combo[] = {KC_J, KC_L, COMBO_END};
const uint16_t PROGMEM cv_combo[] = {KC_C, KC_V, COMBO_END};
combo_t key_combos[COMBO_COUNT] = {
  [JL_ESC] = COMBO(jl_combo, KC_ESC),
  [CV_TAB] = COMBO(cv_combo, KC_TAB),
};

