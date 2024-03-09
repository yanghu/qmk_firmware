#include QMK_KEYBOARD_H
#include "yanghu.h"

bool led_update_user(led_t led_state) {
#ifdef RGBLIGHT_ENABLE
#    ifdef RGBLIGHT_LAYERS
    rgblight_set_layer_state(5, led_state.caps_lock);
#    endif
#endif
/* #ifdef OLED_ENABLE */
/*     oled_render_capslock(led_state.caps_lock); */
/* #endif */
    return true;
}
