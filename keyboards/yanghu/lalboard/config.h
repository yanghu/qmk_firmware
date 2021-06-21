/* Copyright 2021 Yang Hu
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID 0xFEED
#define PRODUCT_ID 0x0204
#define DEVICE_VER 0x0002
#define MANUFACTURER yanghu
#define PRODUCT lalboard

/* key matrix size */
#define MATRIX_ROWS 10
#define MATRIX_COLS 5

/*
 * B2: South
 * B3: center (inverted)*/
#define MATRIX_COL_PINS \
    { B1, B2, B3, B4, B5 }
#define MATRIX_ROW_PINS \
    { A10, A9, A8, A7, A6 }

/* COL2ROW, ROW2COL*/
#define DIODE_DIRECTION COL2ROW

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 2

#define SOFT_SERIAL_PIN A15  // USART TX pin
//  0: about 460800 baud
//  1: about 230400 baud (default)
//  2: about 115200 baud
//  3: about 57600 baud
//  4: about 38400 baud
//  5: about 19200 baud
#define SELECT_SOFT_SERIAL_SPEED 1
#define SERIAL_USART_DRIVER SD1     // USART driver of TX pin. default: SD1
#define SERIAL_USART_TX_PAL_MODE 7  // Pin "alternate function", see the respective datasheet for the appropriate values for your MCU. default: 7
#define SERIAL_USART_TIMEOUT 100    // USART driver timeout. default 100
