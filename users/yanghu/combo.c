#include QMK_KEYBOARD_H

// Combo:
enum combo_events {
  JL_ESC,
  QW_TAB,
};

const uint16_t PROGMEM jl_combo[] = {KC_J, KC_L, COMBO_END};
const uint16_t PROGMEM qw_combo[] = {KC_Q, KC_W, COMBO_END};
combo_t key_combos[COMBO_COUNT] = {
  [JL_ESC] = COMBO(jl_combo, KC_ESC),
  [QW_TAB] = COMBO(qw_combo, KC_TAB),
};

