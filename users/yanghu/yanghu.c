#include QMK_KEYBOARD_H
#include "yanghu.h"

bool led_update_user(led_t led_state) {
#ifdef RGBLIGHT_ENABLE
  rgblight_set_layer_state(4, led_state.caps_lock);
#endif
#ifdef OLED_DRIVER_ENABLE
  oled_render_capslock(led_state.caps_lock);
#endif
  return true;
}
