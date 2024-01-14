/*
Copyright 2019 /u/KeepItUnder

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#define GPIO_INPUT_PIN_DELAY (NUC123_HCLK / 6 / 1000000L)

/* Input Config */
#define FORCE_NKRO

/* RGB Matrix config */
#define MATRIX_ROWS 5
#define MATRIX_COLS 15
#define MATRIX_ROW_PINS { D11, B4, B5, B6, B7 }
#define MATRIX_COL_PINS { B10, B9, C13, C12, C11, C10, C9, C8, A15, A14, A13, D0, D1, D2, B15/*, B8*/ }
#define DIP_SWITCH_MATRIX_GRID { {0,14}, {1,14}, {2,14}, {3,14} }

/* RGB Config */
#define DIODE_DIRECTION COL2ROW
#define RGB_MATRIX_LED_COUNT 75
#define RGB_MATRIX_KEYPRESSES
#define RGB_MATRIX_FRAMEBUFFER_EFFECTS
#define USB_LED_CAPSLOCK_INDEX 30 //Location of caps lock LED in matrix
