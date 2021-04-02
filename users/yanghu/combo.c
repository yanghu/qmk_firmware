#include QMK_KEYBOARD_H

// Combo:
enum combo_events {
  JL_ESC,
};

const uint16_t PROGMEM my_combo[] = {KC_J, KC_L, COMBO_END};
combo_t key_combos[COMBO_COUNT] = {[JL_ESC] = COMBO(my_combo, KC_ESC)};

