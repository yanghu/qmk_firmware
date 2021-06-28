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

#include "quantum.h"

/* This a shortcut to help you visually see your layout.
 *
 * The first section contains all of the arguments representing the physical
 * layout of the board and position of the keys.
 *
 * The second converts the arguments into a two-dimensional array which
 * represents the switch matrix.
 */

// Rows 0-4 are: thumb, fingers 1234
// Columns 0-4 are: east, north, down, south, west
// clang-format off
#define LAYOUT_lalboard( \
    L00, L01, L02, L03, L04, \
    L10, L11, L12, L13, L14, \
    L20, L21, L22, L23, L24, \
    L30, L31, L32, L33, L34, \
    L40, L41, L42, L43, L44, \
    R00, R01, R02, R03, R04, \
    R10, R11, R12, R13, R14, \
    R20, R21, R22, R23, R24, \
    R30, R31, R32, R33, R34, \
    R40, R41, R42, R43, R44 \
) \
{ \
    { L00, L01, L02, L03, L04 }, \
    { L10, L11, L12, L13, L14 }, \
    { L20, L21, L22, L23, L24 }, \
    { L30, L31, L32, L33, L34 }, \
    { L40, L41, L42, L43, L44 }, \
    { R00, R01, R02, R03, R04 }, \
    { R10, R11, R12, R13, R14 }, \
    { R20, R21, R22, R23, R24 }, \
    { R30, R31, R32, R33, R34 }, \
    { R40, R41, R42, R43, R44 } \
}

#define LAYOUT_lalboard_alt( \
    L1D, L2D, L3D, L4D, R1D, R2D, R3D, R4D, \
    L1N, L2N, L3N, L4N, R1N, R2N, R3N, R4N, \
    L1E, L2E, L3E, L4E, R1E, R2E, R3E, R4E, \
    L1S, L2S, L3S, L4S, R1S, R2S, R3S, R4S, \
    L1W, L2W, L3W, L4W, R1W, R2W, R3W, R4W, \
    LTI, LTD, LTM, LTUO, LTLO, \
    RTI, RTD, RTM, RTUO, RTRO  \
) \
{ \
    { LTLO, LTUO, LTD, LTI, LTM}, \
    { L4E, L4N, L4D, L4S, L4W }, \
    { L3E, L3N, L3D, L3S, L3W }, \
    { L2E, L2N, L2D, L2S, L2W }, \
    { L1E, L1N, L1D, L1S, L1W }, \
    { RTRO, RTUO, RTD, RTI, RTM}, \
    { R1E, R1N, R1D, R1S, R1W }, \
    { R2E, R2N, R2D, R2S, R2W }, \
    { R3E, R3N, R3D, R3S, R3W }, \
    { R4E, R4N, R4D, R4S, R4W } \
}
// clang-format on

#define LAYOUT LAYOUT_lalboard
