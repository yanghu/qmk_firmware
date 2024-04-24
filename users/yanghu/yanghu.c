#include QMK_KEYBOARD_H
#include "yanghu.h"

#ifdef RGBLIGHT_ENABLE
bool led_update_user(led_t led_state) {
#    ifdef RGBLIGHT_LAYERS
    rgblight_set_layer_state(5, led_state.caps_lock);
#    endif
/* #ifdef OLED_ENABLE */
/*     oled_render_capslock(led_state.caps_lock); */
/* #endif */
    return true;
}
#endif

/* static os_variant_t current_os; */
bool process_detected_host_os_user(os_variant_t os){
  switch (os) {
    case OS_MACOS:
      default_layer_set((layer_state_t)1 << _BASE_MAC);
      break;
    default:
      default_layer_set((layer_state_t)1 << _BASE);
      break;
  }
  return false;
}


