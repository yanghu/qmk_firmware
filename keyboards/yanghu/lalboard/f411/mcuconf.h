/* Copyright 2020 QMK
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

#include_next <mcuconf.h>

/* USART1 for split comm */
#undef STM32_SERIAL_USE_USART1
#define STM32_SERIAL_USE_USART1 TRUE

/* TIM1 PWM used for audio driver */
#undef STM32_PWM_USE_TIM1
#define STM32_PWM_USE_TIM1 TRUE
/* TIM5 GPT used for audio driver */
#undef STM32_GPT_USE_TIM4
#define STM32_GPT_USE_TIM4 TRUE

/* TIM3 used for WS2812 driver */
#undef STM32_PWM_USE_TIM3
#define STM32_PWM_USE_TIM3 TRUE

/* I2C used for OLED display */
#undef STM32_I2C_USE_I2C1
#define STM32_I2C_USE_I2C1 TRUE

/*
 * HAL driver system settings.
 */
#undef STM32_PLLM_VALUE
#define STM32_PLLM_VALUE 8
#undef STM32_PLLN_VALUE
#define STM32_PLLN_VALUE 192
#undef STM32_PLLP_VALUE
#define STM32_PLLP_VALUE 2
#undef STM32_PLLQ_VALUE
#define STM32_PLLQ_VALUE 4
