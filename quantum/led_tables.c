/*
Copyright 2017 Fred Sundvik
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

#include "led_tables.h"

// clang-format off

#ifdef USE_CIE1931_CURVE
// Lightness curve using the CIE 1931 lightness formula
// Generated by the python script provided in http://jared.geek.nz/2013/feb/linear-led-pwm
const uint8_t CIE1931_CURVE[256] PROGMEM = {
    0,   1,   1,   1,   1,   1,   1,   1,   1,   1,   2,   2,   2,   2,   2,   2,
    2,   2,   2,   3,   3,   3,   3,   3,   3,   3,   3,   4,   4,   4,   4,   4,
    4,   4,   5,   5,   5,   5,   5,   6,   6,   6,   6,   6,   7,   7,   7,   7,
    7,   8,   8,   8,   8,   9,   9,   9,   9,  10,  10,  10,  11,  11,  11,  12,
   12,  12,  13,  13,  13,  14,  14,  14,  15,  15,  15,  16,  16,  17,  17,  17,
   18,  18,  19,  19,  20,  20,  21,  21,  22,  22,  23,  23,  24,  24,  25,  25,
   26,  26,  27,  27,  28,  29,  29,  30,  30,  31,  32,  32,  33,  34,  34,  35,
   36,  36,  37,  38,  38,  39,  40,  41,  41,  42,  43,  44,  45,  45,  46,  47,
   48,  49,  50,  50,  51,  52,  53,  54,  55,  56,  57,  58,  59,  60,  61,  62,
   63,  64,  65,  66,  67,  68,  69,  70,  71,  72,  73,  74,  76,  77,  78,  79,
   80,  81,  83,  84,  85,  86,  88,  89,  90,  91,  93,  94,  95,  97,  98, 100,
  101, 102, 104, 105, 107, 108, 109, 111, 112, 114, 115, 117, 119, 120, 122, 123,
  125, 126, 128, 130, 131, 133, 135, 136, 138, 140, 142, 143, 145, 147, 149, 150,
  152, 154, 156, 158, 160, 162, 163, 165, 167, 169, 171, 173, 175, 177, 179, 181,
  183, 186, 188, 190, 192, 194, 196, 198, 201, 203, 205, 207, 209, 212, 214, 216,
  219, 221, 223, 226, 228, 231, 233, 235, 238, 240, 243, 245, 248, 250, 253, 255
};
#endif

#ifdef USE_CIE1931_16_CURVE
// Lightness curve using the CIE 1931 lightness formula
// Generated by the python script provided in http://jared.geek.nz/2013/feb/linear-led-pwm
const uint16_t CIE1931_16_CURVE[256] PROGMEM = {
		 0,      7,    14,    21,    28,    36,    43,   50,     57,    64, 
		71,     78,    85,    93,   100,   107,   114,   121,   128,   135, 
	 142,    149,   157,   164,   172,   180,   189,   197,   206,   215, 
	 225,    234,   244,   254,   265,   276,   287,   298,   310,   322, 
	 334,    346,   359,   373,   386,   400,   414,   428,   443,   458, 
	 474,    490,   506,   522,   539,   557,   574,   592,   610,   629, 
	 648,    668,   688,   708,   729,   750,   771,   793,   815,   838, 
	 861,    885,   909,   933,   958,   983,  1009,  1035,  1061,  1088, 
	1116,   1144,  1172,  1201,  1230,  1260,  1290,  1321,  1353,  1384, 
	1417,   1449,  1482,  1516,  1550,  1585,  1621,  1656,  1693,  1729, 
	1767,   1805,  1843,  1882,  1922,  1962,  2003,  2044,  2085,  2128, 
	2171,   2214,  2258,  2303,  2348,  2394,  2440,  2487,  2535,  2583, 
	2632,   2681,  2731,  2782,  2833,  2885,  2938,  2991,  3045,  3099, 
	3154,   3210,  3266,  3323,  3381,  3439,  3498,  3558,  3618,  3679, 
	3741,   3803,  3867,  3930,  3995,  4060,  4126,  4193,  4260,  4328, 
	4397,   4466,  4536,  4607,  4679,  4752,  4825,  4899,  4973,  5049, 
	5125,   5202,  5280,  5358,  5437,  5517,  5598,  5680,  5762,  5845, 
	5929,   6014,  6100,  6186,  6273,  6361,  6450,  6540,  6630,  6722, 
	6814,   6907,  7001,  7095,  7191,  7287,  7385,  7483,  7582,  7682, 
	7782,   7884,  7986,  8090,  8194,  8299,  8405,  8512,  8620,  8729, 
	8838,   8949,  9060,  9173,  9286,  9400,  9516,  9632,  9749,  9867, 
	9986,  10106, 10227, 10348, 10471, 10595, 10720, 10845, 10972, 11100, 
	11228, 11358, 11489, 11620, 11753, 11887, 12021, 12157, 12294, 12432, 
	12570, 12710, 12851, 12993, 13136, 13279, 13424, 13570, 13718, 13866, 
	14015, 14165, 14317, 14469, 14622, 14777, 14933, 15089, 15247, 15406, 
	15566, 15727, 15890, 16053, 16217, 16383
};
#endif

// clang-format on
