/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

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

//#define USE_MATRIX_I2C

/* Select hand configuration */

#define MASTER_LEFT
// #define MASTER_RIGHT
// #define EE_HANDS

#define USE_SERIAL_PD2

#define TAPPING_TERM 120

#ifdef RGB_MATRIX_ENABLE
#  define RGB_MATRIX_KEYPRESSES // reacts to keypresses
#  define RGB_DISABLE_WHEN_USB_SUSPENDED // turn off effects when suspended
#  define RGB_MATRIX_FRAMEBUFFER_EFFECTS
#  define RGB_MATRIX_MAXIMUM_BRIGHTNESS 150 // limits maximum brightness of LEDs to 150 out of 255. Higher may cause the controller to crash. 
#  define RGB_MATRIX_HUE_STEP 8
#  define RGB_MATRIX_SAT_STEP 8
#  define RGB_MATRIX_VAL_STEP 8
#  define RGB_MATRIX_SPD_STEP 10

// https://docs.qmk.fm/#/feature_rgb_matrix?id=rgb-matrix-effects
/* #  define ENABLE_RGB_MATRIX_ALPHAS_MODS */
// enabled only if RGB_MATRIX_FRAMEBUFFER_EFFECTS is defined
#  define ENABLE_RGB_MATRIX_CYCLE_PINWHEEL
#  define ENABLE_RGB_MATRIX_TYPING_HEATMAP
/* #  define ENABLE_RGB_MATRIX_DIGITAL_RAIN */
// enabled only of RGB_MATRIX_KEYPRESSES or RGB_MATRIX_KEYRELEASES is defined
/* #  define ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE */
/* #  define ENABLE_RGB_MATRIX_MULTISPLASH */
#  ifdef RGB_MATRIX_TYPING_HEATMAP_DECREASE_DELAY_MS
#    undef RGB_MATRIX_TYPING_HEATMAP_DECREASE_DELAY_MS
#    define RGB_MATRIX_TYPING_HEATMAP_DECREASE_DELAY_MS  250
#  endif
#  define RGB_MATRIX_STARTUP_MODE RGB_MATRIX_TYPING_HEATMAP
#  define SPLIT_LAYER_STATE_ENABLE
#endif

#ifdef DEBOUNCE
#  undef DEBOUNCE
#  define DEBOUNCE 2
#endif

/* #define WPM_UNFILTERED */
/* #define WPM_LAUNCH_CONTROL */
/* #define OLED_FONT_H "keyboards/crkbd/lib/glcdfont.c" */

#ifdef OLED_ENABLE
#  define OLED_SCROLL_TIMEOUT 30000
#endif
