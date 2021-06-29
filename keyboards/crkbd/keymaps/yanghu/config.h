#pragma once

#define MASTER_LEFT
#define USE_SERIAL_PD2

#ifdef RGBLIGHT_ENABLE
    #undef RGBLED_NUM
    #define RGBLIGHT_ANIMATIONS
    #define RGBLED_NUM 27
    #define RGBLIGHT_LIMIT_VAL 120
    #define RGBLIGHT_HUE_STEP 10
    #define RGBLIGHT_SAT_STEP 17
    #define RGBLIGHT_VAL_STEP 17
#endif
#ifndef OLED_FONT_H 
#define OLED_FONT_H "keyboards/crkbd/lib/glcdfont.c"
#endif
