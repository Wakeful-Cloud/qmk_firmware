/* Copyright 2019 /u/KeepItUnder
 * Copyright 2023 Wakeful Cloud
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

#include <stdint.h>
#include <stdbool.h>

typedef struct mbi_led {
    uint8_t row;
    uint8_t col;
} __attribute__((packed)) mbi_led;

extern const mbi_led g_mbi_leds[RGB_MATRIX_LED_COUNT];

/* #define MBI5043_CFGREG_DEFAULT 0x002b0ul */
#define MBI5043_CFGREG_DEFAULT 0b1000010000000000u

#define MBI5043_GCLK_GPIO PA12
#define MBI5043_GCLK_SRC PWM0
#define MBI5043_GCLK_SPD 2000000
#define MBI5043_DCLK_GPIO PD4
#define MBI5043_LE PD3

#define MBI5043_ROW_COUNT 5
#define MBI5043_REFRESH_SPD 2000

void MBI5043_init(void);

void MBI5043_set_current_gain(uint8_t gain);
void MBI5043_write_config_register(uint16_t regValue);

void MBI5043_set_color(int index, uint8_t red, uint8_t green, uint8_t blue);
void MBI5043_set_color_all(uint8_t red, uint8_t green, uint8_t blue);

void MBI5043_update_pwm_buffers(void);
void MBI5043_write_pwm_buffers(void);

void MBI5043_planar_recode(int row, int column, uint8_t red, uint8_t green, uint8_t blue);

void MBI5043_disable_rows(void);
void MBI5043_disable_row(int row);
void MBI5043_enable_row(int row);