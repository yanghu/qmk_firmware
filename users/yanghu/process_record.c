#include "process_record.h"
#include "action.h"
#include "action_util.h"
#include "keycode.h"
#include QMK_KEYBOARD_H
#include "keycodes.h"
#include "layers.h"

__attribute__((weak)) layer_state_t layer_state_set_keymap(layer_state_t state){
  return state;
}

// Initialize variable holding the binary
// representation of active modifiers.
uint8_t mod_state;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // By default ask qmk to process the keycode.
  bool retval = true;
  // Store the current modifier state in the variable for later reference
  mod_state = get_mods();
  static bool altkey_registered;
  static bool guikey_registered;
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
            retval = false;
          } else {
            retval = true;
          }
        } else { // on release of KC_BSPC
          // In case KC_DEL is still being sent even after the release of KC_BSPC
          if (delkey_registered) {
            unregister_code(KC_DEL);
            delkey_registered = false;
            retval = false;
          } else {
            retval = true;
          }
        }
      } // case kc_bspc
      break;
    case MO(_SYMBOL):
    case MO(_SYMBOL_MAC):
      // When releasing nav ent and alt key was registered, unregister it.
      if (!record->event.pressed && altkey_registered) {
        unregister_mods(MOD_BIT(KC_LALT));
        altkey_registered = false;
      }
      if (!record->event.pressed && guikey_registered) {
        unregister_mods(MOD_BIT(KC_LGUI));
        guikey_registered = false;
      }
      retval = true;
      break;
    case KC_ATAB:
      if (record->event.pressed) {
        // first register alt if not already
        if (!altkey_registered) {
          add_mods(MOD_BIT(KC_LALT));
          altkey_registered = true;
        }
        register_code(KC_TAB);
      } else {
        unregister_code(KC_TAB);
      }
      retval = false;
      break;
    case KC_GTAB:
      if (record->event.pressed) {
        // first register alt if not already
        if (!guikey_registered) {
          add_mods(MOD_BIT(KC_LGUI));
          guikey_registered = true;
        }
        register_code(KC_TAB);
      } else {
        unregister_code(KC_TAB);
      }
      retval = false;
      break;
    case KC_GTILDE:
      if (record->event.pressed) {
        // first register alt if not already
        if (!guikey_registered) {
          add_mods(MOD_BIT(KC_LGUI | KC_LSFT));
          guikey_registered = true;
        }
        register_code(KC_GRV);
      } else {
        unregister_mods(MOD_BIT(KC_LSFT));
        unregister_code(KC_GRV);
      }
      retval = false;
      break;
  } // switch
  return process_record_keymap(keycode, record) && retval;
};


layer_state_t layer_state_set_user(layer_state_t state) {
  state = update_tri_layer_state(state, _NAV, _SYMBOL, _FUNC);
  return layer_state_set_keymap(state);
}
