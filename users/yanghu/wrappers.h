/* Borrowed from drashna's userspace.
 */

#pragma once

/* Define blobks to be shared in different keyboard layouts
 */

// clang-format off
// qwerty letters.

#define __________QWERTY_BASE_L1__________       KC_Q,    KC_W,    KC_E,    KC_R,    KC_T
#define __________QWERTY_BASE_L2__________       HOME_A,  HOME_S,  KC_D,    HOME_F,  KC_G
#define __________QWERTY_BASE_L3__________       KC_Z,    KC_X,    KC_C,    KC_V,    KC_B

#define __________QWERTY_BASE_R1__________       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P
#define __________QWERTY_BASE_R2__________       KC_H,    KC_J,    HOME_K,  KC_L,    KC_SCLN
#define __________QWERTY_BASE_R3__________       KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH

#define __________QWERTY_L1__________       KC_TAB,     __________QWERTY_BASE_L1__________
#define __________QWERTY_L2__________       HY_S_CAPS,  __________QWERTY_BASE_L2__________
#define __________QWERTY_L3__________       KC_LALT,    __________QWERTY_BASE_L3__________

#define __________QWERTY_R1__________       __________QWERTY_BASE_R1__________, KC_BSPC
#define __________QWERTY_R2__________       __________QWERTY_BASE_R2__________, KC_QUOT
#define __________QWERTY_R3__________       __________QWERTY_BASE_R3__________, LT(_PSCR, KC_ENT)

// Dvorak base

#define __________DVORAK_BASE_L1__________       KC_SCLN, KC_COMMA, KC_DOT, KC_P,    KC_Y
#define __________DVORAK_BASE_L2__________       HOME_A,  HOME_O,  KC_E,    HOME_U,  KC_I
#define __________DVORAK_BASE_L3__________       KC_Z,    KC_Q,    KC_J,    KC_K,    KC_X

#define __________DVORAK_BASE_R1__________       KC_F,    KC_G,    KC_C,    KC_R,    KC_L
#define __________DVORAK_BASE_R2__________       KC_D,    KC_H,    HOME_T,  KC_N,    KC_S
#define __________DVORAK_BASE_R3__________       KC_B,    KC_M,    KC_W,    KC_V,  KC_SLSH


#define __________DVORAK_L1__________       KC_TAB,     __________DVORAK_BASE_L1__________
#define __________DVORAK_L2__________       HY_S_CAPS,  __________DVORAK_BASE_L2__________
#define __________DVORAK_L3__________       KC_LALT,    __________DVORAK_BASE_L3__________

#define __________DVORAK_R1__________       __________DVORAK_BASE_R1__________, KC_BSPC
#define __________DVORAK_R2__________       __________DVORAK_BASE_R2__________, KC_QUOT
#define __________DVORAK_R3__________       __________DVORAK_BASE_R3__________, LT(_PSCR, KC_ENT)

// Symbol
// ______________________________________________________________________________
// |  ~  |  !  |  @  |  #  |  $  |  %  |----|  ^  |  &  |  *  |  (  |  )  |     |
// ------------------------------------------------------------------------------
// |A-Tab|  [  |  {  |  }  |  ]  | g-␣ |----| c-^ |  -  |  =  |  _  |  :  |  "  |
// ------------------------------------------------------------------------------
// |     |  |  |  `  |  \  |  ~  | c-␣ |----|     |  +  |  <  |  >  |  ?  |TO(LAYERS|
// ------------------------------------------------------------------------------
#define __________SYMBOL_L1__________       KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC
#define __________SYMBOL_L2__________       KC_ATAB,  KC_LBRC, KC_RBRC, KC_LCBR, KC_RCBR, G(KC_SPACE)
#define __________SYMBOL_L3__________       _______, KC_PIPE, KC_GRV, KC_BSLS, KC_TILD, C(KC_SPACE)

#define __________SYMBOL_R1__________       KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______
#define __________SYMBOL_R2__________       C(KC_CIRC), KC_MINS, KC_EQL,  KC_UNDS, KC_COLN, KC_DQUO
#define __________SYMBOL_R3__________       XXXXXXX, KC_PLUS, KC_LT,   KC_GT,   KC_QUES, TO(_LAYER_SEL)

#define __________BLANK__________        _______, _______, _______, _______, _______, _______
#define __________NOKEY__________        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
#define __________BLANK5__________       _______, _______, _______, _______, _______
#define __________NOKEY5__________       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX

#define __________NAV_L1__________       KC_TAB,  A(KC_1), A(KC_2), A(KC_3), A(KC_4), A(KC_5)
#define __________NAV_L2__________       XXXXXXX, XXXXXXX, KC_LSFT, KC_PGDN, KC_LCTL, XXXXXXX
#define __________NAV_L3__________       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX

#define __________NAV_R1__________       KC_HOME, KC_PGUP, KC_END, XXXXXXX, XXXXXXX, _______
#define __________NAV_R2__________       KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, XXXXXXX, XXXXXXX
#define __________NAV_R3__________       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX

#define __________NUM_L1__________       KC_ESC, KC_TAB,  KC_DEL, KC_1,  KC_2,    KC_3
#define __________NUM_L2__________       OS_GUI, OS_CTRL, OS_SHFT, OS_ALT, XXXXXXX, XXXXXXX
#define __________NUM_L3__________       _______,  KC_LGUI, XXXXXXX, XXXXXXX, XXXXXXX, TO(_BASE)

#define __________NUM_R1__________       KC_6,    KC_7, KC_8,  KC_9,   KC_PPLS, _______
#define __________NUM_R2__________       XXXXXXX, KC_4, KC_5,  KC_6,   KC_PMNS, KC_PAST
#define __________NUM_R3__________       XXXXXXX, KC_1, KC_2,  KC_3,   KC_PSLS, KC_PEQL

#define __________FUNC_L1__________      RESET, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5
#define __________FUNC_L2__________      KC_LCTRL, KC_F11, KC_F12, XXXXXXX, XXXXXXX, XXXXXXX
#define __________FUNC_L3__________      TO(_LAYER_SEL), __________BLANK5__________ 
#define __________FUNC_R1__________      KC_F6, KC_F7,   KC_F8,   KC_F9,   KC_F10,  TO(_DEBUG_LAYER)
#define __________FUNC_R3__________      __________BLANK5__________ , TO(_LAYER_SEL)

#define __________DEBUG_L1__________      TO(_BASE), DEBUG, _______, _______, _______, _______

#define __________LAYER_SEL_L1__________  TO(_BASE), TO(_CAD), _______, _______, _______, _______
#define __________LAYER_SEL_L2__________  _______, _______, _______, _______, TO(_NUMPAD), _______


#define __________CAD_L1__________       KC_ESC,    __________BLANK5__________
#define __________CAD_L2__________       HY_S_CAPS, __________BLANK5__________
#define __________CAD_L3__________       __________BLANK__________
#define __________CAD_L4__________       SH_OS,  TT(_CAD_NUM), _______

#define __________CAD_R1__________       __________BLANK5__________, KC_DEL
#define __________CAD_R2__________       __________BLANK__________
#define __________CAD_R3__________       __________BLANK5__________, KC_LSFT
#define __________CAD_R4__________       _______,  _______, TO(_BASE)

#define __________CAD_NUM_L1__________  _______, KC_AT, KC_9, KC_8, KC_7, KC_PLUS
#define __________CAD_NUM_L2__________  KC_GRV, KC_COMM, KC_6, KC_5, KC_4, KC_MINS
#define __________CAD_NUM_L3__________  _______, KC_DOT,  KC_3, KC_2, KC_1, KC_LT
#define __________CAD_NUM_L4__________  KC_0,  _______, _______
