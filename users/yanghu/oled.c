#include "action_util.h"
#include "keycode.h"
#include "quantum.h"
#include QMK_KEYBOARD_H
#include "layers.h"

// Some characters position:
// alt: 84 85 86/a..../c...
// shift:87 88 89/a.../c...
// ctrl: 8c 8d/a.../
// capslock: 9c-9f/b.../d...
// numlock: 98-9b/b.../d...
void oled_render_layer(void) {
  static const char PROGMEM numlock_logo[] = {
    0x98, 0x99, 0x9a, 0x9b, 10,
    0xb8, 0xb9, 0xba, 0xbb, 10,
    0xd8, 0xd9, 0xda, 0xdb, 10,
    0};
  static const char PROGMEM symbol_logo[] = {
    0x80, 0x81, 0x82, 0x83, 10,
    0xa0, 0xa1, 0xa2, 0xa3, 10,
    0xc0, 0xc1, 0xc2, 0xc3, 10,
    0};
  static const char PROGMEM qmk_logo[] = {
    0x8e, 0x8f, 0x90, 0x91, 10,
    0xae, 0xaf, 0xb0, 0xb1, 10,
    0xce, 0xcf, 0xd0, 0xd1, 10,
    0};
  if (IS_LAYER_ON(_SYMBOL)) {
    oled_write_P(symbol_logo, false);
  } else if (IS_LAYER_ON(_NUMPAD)){
    oled_write_P(numlock_logo, false);
  } else if (IS_LAYER_ON(_BASE)){
    oled_write_P(qmk_logo, false);
  } else {
    oled_write_ln(" ", false);
    oled_write_ln(" ", false);
    oled_write_ln(" ", false);
    oled_write_ln(" ", false);
  }
}

void oled_render_mods(void) {
  static const char PROGMEM ctrl[] = {
    0x8c, 0x8d, 10, 
    0xac, 0xad, 10,
    0x20, 0x20, 10,
    0};
  static const char PROGMEM shift[] = {
    0x87,0x88,0x89,10,
    0xa7,0xa8,0xa9,10,
    0xc7,0xc8,0xc9,10, 0
  };
  static const char PROGMEM alt[] = {
    0x84, 0x85, 0x86, 10,
    0xa4, 0xa5, 0xa6, 10,
    0xc4, 0xc5, 0xc6, 10,
    0};
  static const char PROGMEM ctrl_alt[] = {
    0x8c, 0x8d, 0x84, 0x85, 0x86,
    0xac, 0xad, 0xa4, 0xa5, 0xa6,
    0x20, 0x20, 0xc4, 0xc5, 0xc6,
    0};

  static const char PROGMEM ctrl_shift[] = {
    0x8c, 0x8d, 0x87,0x88,0x89,
    0xac, 0xad, 0xa7,0xa8,0xa9,
    0x20, 0x20, 0xc7,0xc8,0xc9, 0
    };
  static const char PROGMEM c_a_shift[] = {
    0x8c, 0x8d, 0x84, 0x85, 0x86,
    0xac, 0xad, 0xa4, 0xa5, 0xa6,
    0x20, 0x20, 0xc4, 0xc5, 0xc6,
    0x87,0x88,0x89,10,
    0xa7,0xa8,0xa9,10,
    0xc7,0xc8,0xc9,10, 0
    };
  // Now check mod status and render.
  static uint8_t mods;
  mods = get_mods();
  if ((mods & MOD_MASK_CTRL) && (mods & MOD_MASK_ALT) && (mods & MOD_MASK_SHIFT)) {
    oled_write_P(c_a_shift, false);
  } else if ((mods & MOD_MASK_CTRL) && (mods & MOD_MASK_ALT)) {
    oled_write_P(ctrl_alt, false);
  } else if ((mods & MOD_MASK_CTRL) && (mods & MOD_MASK_SHIFT)) {
    oled_write_P(ctrl_shift, false);
  } else if ((mods & MOD_MASK_SHIFT) && (mods & MOD_MASK_ALT)) {
    oled_write_P(alt, false);
    oled_write_P(shift, false);
  } else if (mods & MOD_MASK_CTRL) {
    oled_write_P(ctrl, false);
  } else if (mods & MOD_MASK_ALT) {
    oled_write_P(alt, false);
  } else if (mods & MOD_MASK_SHIFT) {
    oled_write_P(shift, false);
  } else {
    for (int i=0; i<6; ++i) {
      oled_write_ln(" ", false);
    }
  }
  return;
}
