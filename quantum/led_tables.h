/*
Copyright 2017 Fred Sundvik
Copyright 2019 /u/KeepItUnder

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published bythe Free Software Foundation, either version 2 of the License, or
(at your option) any later version.
This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.
You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include "progmem.h"
#include <stdint.h>

#ifdef USE_CIE1931_CURVE
extern const uint8_t CIE1931_CURVE[] PROGMEM;
#endif

#ifdef USE_CIE1931_16_CURVE
extern const uint16_t CIE1931_16_CURVE[] PROGMEM;
#endif