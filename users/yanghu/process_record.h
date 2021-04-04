#pragma once
#include QMK_KEYBOARD_H

// For keymaps to add specific actions.
bool process_record_keymap(uint16_t keycode, keyrecord_t *record);

layer_state_t layer_state_set_keymap(layer_state_t state);
