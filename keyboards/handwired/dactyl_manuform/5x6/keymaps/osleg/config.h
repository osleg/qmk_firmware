/*
Copyright 2012 Jun Wako <wakojun@gmail.com>

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
#define USE_SERIAL_PD2
#define MASTER_LEFT

// SPLIT
#define SPLIT_OLED_ENABLE
// #define SPLIT_WPM_ENABLE
#undef SOFT_SERIAL_PIN
#define SOFT_SERIAL_PIN D2

#define TAPPING_TERM 150

// RGB
#undef RGBLED_NUM
#define RGBLED_NUM 20
#define RGB_DI_PIN D3
#define RGBLED_SPLIT {10, 10}
#define RGBLIGHT_SPLIT
/* #define RGBLIGHT_EFFECT_RAINBOW_SWIRL */
#define RGBLIGHT_HUE_STEP 2
#define RGBLIGHT_SAT_STEP 16
#define RGBLIGHT_VAL_STEP 6
/* #define RGBLIGHT_SLEEP */
/* #define RGBLIGHT_ANIMATIONS */
#define RGBLIGHT_EFFECT_TWINKLE
#define RGBLIGHT_EFFECT_KNIGHT
/* #define RGBLIGHT_EFFECT_RAINBOW_SWIRL */
/* #define RGBLIGHT_EFFECT_KNIGHT_LENGTH 3 */
/* #define RGBLIGHT_LAYERS */
/* #define RGBLIGHT_MAX_LAYERS 5 */

/* #define RGBLIGHT_LAYERS_OVERRIDE_RGB_OFF */
/* #define RGBLIGHT_LAYERS_RETAIN_VAL */

// OLED
#define OLED_TIMEOUT 30000
#define OLED_BRIGHTNESS 96

#ifdef DEBOUNCE
#  undef DEBOUNCE
#  define DEBOUNCE 8
#endif


