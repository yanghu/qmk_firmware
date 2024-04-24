#include "action_util.h"
#include "keycode.h"
#include "quantum.h"
#include QMK_KEYBOARD_H
#include "layers.h"

// Some characters position:
// alt: 84 85 86/a..../c...
// shift:87 88 89/a.../c...
// ctrl: b6 b6/d.../
// capslock: 9c-9f/b.../d...
// numlock: 98-9b/b.../d...
void oled_render_layer(void) {
    static const char PROGMEM numlock_logo[] = {0x98, 0x99, 0x9a, 0x9b, 10, 0xb8, 0xb9, 0xba, 0xbb, 10, 0xd8, 0xd9, 0xda, 0xdb, 10, 0};
    /* static const char PROGMEM cmd_logo[] = { */
    /*   0x80, 0x81, 0x82, 0x83, 10, */
    /*   0xa0, 0xa1, 0xa2, 0xa3, 10, */
    /*   0xc0, 0xc1, 0xc2, 0xc3, 10, */
    /*   0}; */
    static const char PROGMEM nav_logo[]    = {0x92, 0x93, 0x94, 0x95, 10, 0xb2, 0xb3, 0xb4, 0xb5, 10, 0xd2, 0xd3, 0xd4, 0xd5, 10, 0};
    static const char PROGMEM symbol_logo[] = {0x8a, 0x8b, 0x8c, 0x8d, 10, 0xaa, 0xab, 0xac, 0xad, 10, 0xca, 0xcb, 0xcc, 0xcd, 10, 0};
    static const char PROGMEM qmk_logo[]    = {0x8e, 0x8f, 0x90, 0x91, 10, 0xae, 0xaf, 0xb0, 0xb1, 10, 0xce, 0xcf, 0xd0, 0xd1, 10, 0};
    switch (get_highest_layer(layer_state)) {
      case _BASE:
      case _BASE_MAC:
      case _BASE_SIMPLE:
        oled_write_P(qmk_logo, false);
        return;
      case _SYMBOL:
      case _SYMBOL_MAC:
        oled_write_P(symbol_logo, false);
        return;
      case _NAV:
      case _NAV_MAC:
        oled_write_P(nav_logo, false);
        return;
      case _NUMPAD:
        oled_write_P(numlock_logo, false);
        return;
      case _FUNC:
        oled_write_ln("FUNC", false);
        break;
    }
    for (int i = 0; i < 2; ++i) {
      oled_write_ln(" ", false);
    }

/*     if (IS_LAYER_ON(_SYMBOL) | IS_LAYER_ON(_SYMBOL_MAC)) { */
/*         oled_write_P(symbol_logo, false); */
/*     } else if (IS_LAYER_ON(_NUMPAD)) { */
/*         oled_write_P(numlock_logo, false); */
/*     } else if (IS_LAYER_ON(_NAV) | IS_LAYER_ON(_NAV_MAC)) { */
/*         oled_write_P(nav_logo, false); */
/*     } else if (IS_LAYER_ON(_BASE) | IS_LAYER_ON(_BASE_MAC) | IS_LAYER_ON(_BASE_SIMPLE)) { */
/*         oled_write_P(qmk_logo, false); */
/*     } else { */
/*         if (IS_LAYER_ON(_LAYER_SEL)) { */
/*             oled_write_ln("SEL", false); */
/*         } else if (IS_LAYER_ON(_CAD_NUM)) { */
/*             oled_write_ln("CAD.N", false); */
/*         } else if (IS_LAYER_ON(_CAD)) { */
/*             oled_write_ln("CAD", false); */
/*         } else if (IS_LAYER_ON(_FUNC)) { */
/*             oled_write_ln("FUNC", false); */
/*         } else if (IS_LAYER_ON(_DEBUG_LAYER)) { */
/*             oled_write_ln("DEBUG", false); */
/*         } else if (IS_LAYER_ON(_ENC_VIM)) { */
/*             oled_write_ln("enc_vim", false); */
/*         } else if (IS_LAYER_ON(_ENC_SCROLL)) { */
/*             oled_write_ln("enc_scroll", false); */
/*         } else { */
/*             oled_write_ln("?????", false); */
/*         } */
/*         oled_write_ln(" ", false); */
/*         oled_write_ln(" ", false); */
/*         oled_write_ln(" ", false); */
/*     } */
}

uint8_t osmods;

void oled_render_mods(void) {
    static const char PROGMEM ctrl[]     = {0xb6, 0xb7, 10, 0xd6, 0xd7, 10, 0x20, 0x20, 10, 0};
    static const char PROGMEM shift[]    = {0x87, 0x88, 0x89, 10, 0xa7, 0xa8, 0xa9, 10, 0xc7, 0xc8, 0xc9, 10, 0};
    static const char PROGMEM alt[]      = {0x84, 0x85, 0x86, 10, 0xa4, 0xa5, 0xa6, 10, 0xc4, 0xc5, 0xc6, 10, 0};
    static const char PROGMEM ctrl_alt[] = {0xb6, 0xb7, 0x84, 0x85, 0x86, 0xd6, 0xd7, 0xa4, 0xa5, 0xa6, 0x20, 0x20, 0xc4, 0xc5, 0xc6, 0};
    static const char PROGMEM cmd_logo[] = {
      0x80, 0x81, 0x82, 0x83, 10,
      0xa0, 0xa1, 0xa2, 0xa3, 10,
      0xc0, 0xc1, 0xc2, 0xc3, 10,
      0};

    static const char PROGMEM ctrl_shift[] = {0xb6, 0xb7, 0x87, 0x88, 0x89, 0xd6, 0xd7, 0xa7, 0xa8, 0xa9, 0x20, 0x20, 0xc7, 0xc8, 0xc9, 0};
    static const char PROGMEM c_a_shift[]  = {0xb6, 0xb7, 0x84, 0x85, 0x86, 0xd6, 0xd7, 0xa4, 0xa5, 0xa6, 0x20, 0x20, 0xc4, 0xc5, 0xc6, 0x87, 0x88, 0x89, 10, 0xa7, 0xa8, 0xa9, 10, 0xc7, 0xc8, 0xc9, 10, 0};
    // Now check mod status and render.
    static uint8_t mods;
    mods = get_mods() | osmods;
    if ((mods & MOD_MASK_CTRL) && (mods & MOD_MASK_ALT) && (mods & MOD_MASK_SHIFT)) {
        oled_write_P(c_a_shift, false);
    } else if ((mods & MOD_MASK_CTRL) && (mods & MOD_MASK_ALT)) {
        oled_write_P(ctrl_alt, false);
        for (int i = 0; i < 3; ++i) {
            oled_write_ln(" ", false);
        }
    } else if ((mods & MOD_MASK_CTRL) && (mods & MOD_MASK_SHIFT)) {
        oled_write_P(ctrl_shift, false);
        for (int i = 0; i < 3; ++i) {
            oled_write_ln(" ", false);
        }
    } else if ((mods & MOD_MASK_SHIFT) && (mods & MOD_MASK_ALT)) {
        oled_write_P(alt, false);
        oled_write_P(shift, false);
    } else if (mods & MOD_MASK_GUI) {
        oled_write_P(cmd_logo, false);
        for (int i = 0; i < 3; ++i) {
            oled_write_ln(" ", false);
        }
    } else if (mods & MOD_MASK_CTRL) {
        oled_write_P(ctrl, false);
        for (int i = 0; i < 3; ++i) {
            oled_write_ln(" ", false);
        }
    } else if (mods & MOD_MASK_ALT) {
        oled_write_P(alt, false);
        for (int i = 0; i < 3; ++i) {
            oled_write_ln(" ", false);
        }
    } else if (mods & MOD_MASK_SHIFT) {
        oled_write_P(shift, false);
        for (int i = 0; i < 3; ++i) {
            oled_write_ln(" ", false);
        }
    } else {
        for (int i = 0; i < 6; ++i) {
            oled_write_ln(" ", false);
        }
    }
    return;
}

void oled_render_os(void) {
    static const char PROGMEM apple_logo[]     = {156,157,10,188,189,0};
    static const char PROGMEM windows_logo[]    = {158,159,10,190,191,0};
    os_variant_t detected_os = detected_host_os();
    switch (detected_os) {
      case OS_MACOS:
        oled_write_P(apple_logo, false);
        break;
      default:
        oled_write_P(windows_logo, false);
        break;
    }
    return;
}

void oneshot_mods_changed_user(uint8_t mods) { osmods = mods; }
