/* Borrowed from drashna's userspace.
 */

#pragma once

/* Define blobks to be shared in different keyboard layouts
 */

// clang-format off
// qwerty letters.
#define __________QWERTY_L1__________       KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T
#define __________QWERTY_L2__________       NUM_CTRL, HOME_A,  KC_S,  KC_D,    HOME_F,  KC_G
#define __________QWERTY_L3__________       HY_S_CAPS,KC_Z,    KC_X,    KC_C,    KC_V,    KC_B

#define __________QWERTY_R1__________       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,   KC_BSPC
#define __________QWERTY_R2__________       KC_H,    KC_J,    HOME_K,  KC_L,    KC_SCLN, KC_QUOT
#define __________QWERTY_R3__________       KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, LT(_PSCR, KC_ENT)

// Symbol
// ______________________________________________________________________________
// |  ~  |  !  |  @  |  #  |  $  |  %  |----|  ^  |  &  |  *  |  (  |  )  |     |
// ------------------------------------------------------------------------------
// |  `  |  [  |  ]  |  {  |  }  |  g  |----|  h  |  -  |  =  |  _  |  :  |  "  |
// ------------------------------------------------------------------------------
// |     |  |  |  `  |  \  |  ~  |     |----|     |  +  |  <  |  >  |  ?  |TO(LAYERS|
// ------------------------------------------------------------------------------
#define __________SYMBOL_L1__________       KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC
#define __________SYMBOL_L2__________       KC_GRV,  KC_LBRC, KC_RBRC, KC_LCBR, KC_RCBR, _______
#define __________SYMBOL_L3__________      _______, KC_PIPE, KC_GRV, KC_BSLS, KC_TILD, XXXXXXX

#define __________SYMBOL_R1__________       KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______
#define __________SYMBOL_R2__________       _______, KC_MINS, KC_EQL,  KC_UNDS, KC_COLN, KC_DQUO
#define __________SYMBOL_R3__________       XXXXXXX, KC_PLUS, KC_LT,   KC_GT,   KC_QUES, TO(_LAYER_SEL)

#define __________BLANK__________        _______, _______, _______, _______, _______, _______
#define __________NOKEY_________         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
#define __________BLANK5__________       _______, _______, _______, _______, _______
#define __________NOKEY5_________        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX

#define __________NAV_L1__________       KC_TAB,  A(KC_1), A(KC_2), A(KC_3), A(KC_4), A(KC_5)
#define __________NAV_L2__________       XXXXXXX, XXXXXXX, KC_LSFT, KC_PGDN, KC_LCTL, XXXXXXX
#define __________NAV_R1__________       KC_HOME, KC_PGUP, KC_END, XXXXXXX, XXXXXXX, _______
#define __________NAV_R2__________       KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, XXXXXXX, XXXXXXX

#define __________NUM_L1__________       KC_TAB,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5
#define __________NUM_L2__________       _______, KC_TAB, KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX
#define __________NUM_L3__________       KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX

#define __________NUM_R1__________       KC_6,    KC_7, KC_8,  KC_9,   KC_PPLS, _______
#define __________NUM_R2__________       XXXXXXX, KC_4, KC_5,  KC_6,   KC_PMNS, KC_PAST
#define __________NUM_R3__________       XXXXXXX, KC_1, KC_2,  KC_3,   KC_PSLS, KC_PEQL

#define __________FUNC_L1__________      RESET, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5
#define __________FUNC_L2__________      KC_LCTRL, KC_F11, KC_F12, XXXXXXX, XXXXXXX, XXXXXXX
#define __________FUNC_R1__________      KC_F6, KC_F7,   KC_F8,   KC_F9,   KC_F10,  TO(_DEBUG_LAYER)

#define __________DEBUG_L1__________      TO(_BASE), DEBUG, _______, _______, _______, _______

#define __________LAYER_SEL_L1__________  TO(_BASE), _______, _______, _______, _______, _______

