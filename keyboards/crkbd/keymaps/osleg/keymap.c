/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

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

#include QMK_KEYBOARD_H
#include "vimmode.h"
#include "action_layer.h"
#include "caps_word.h"
/* #include "process_auto_shift.h" */

#define L_BASE 0
#define L_DVORAK 1
#define L_LOWER 2
#define L_RAISE 3
#define L_ADJUST 4
#define L_VIM 5

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[L_BASE] = LAYOUT_split_3x6_3(
 KC_ESC,   KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,                                    KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,KC_BSLS,
KC_LCTL,   KC_A,   KC_S,   KC_D,   KC_F,   KC_G,                                    KC_H,   KC_J,   KC_K,   KC_L,KC_SCLN,KC_QUOT,
KC_LSPO,   KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,                                    KC_N,   KC_M,KC_COMM, KC_DOT,KC_SLSH,KC_RSPC,
                                KC_LGUI,LT(L_LOWER,KC_TAB),KC_SPC,        KC_BSPC,LT(L_RAISE,KC_ENT),KC_RALT),

	[L_DVORAK] = LAYOUT_split_3x6_3(
 KC_ESC,KC_QUOT,KC_COMM, KC_DOT,   KC_P,   KC_Y,                                    KC_F,   KC_G,   KC_C,   KC_R,   KC_L,KC_BSLS,
KC_LCTL,   KC_A,   KC_O,   KC_E,   KC_U,   KC_I,                                    KC_D,   KC_H,   KC_T,   KC_N,   KC_S,KC_SLSH,
KC_LSPO,KC_SCLN,   KC_Q,   KC_J,   KC_K,   KC_X,                                    KC_B,   KC_M,   KC_W,   KC_V,   KC_Z,KC_RSPC,
                                KC_LGUI,LT(L_LOWER,KC_TAB),KC_SPC,        KC_BSPC,LT(L_RAISE,KC_ENT),KC_LALT),

	[L_LOWER] = LAYOUT_split_3x6_3(
 KC_GRV,KC_EXLM,  KC_AT,KC_HASH, KC_DLR,KC_PERC,                                    KC_ASTR,KC_7,   KC_8,   KC_9,   KC_PPLS,  _______,
_______,KC_CIRC,KC_AMPR,KC_UNDS,KC_LBRC,KC_RBRC,                                    KC_SLSH,KC_4,   KC_5,   KC_6,   KC_MINS,  _______,
_______,KC_SCLN,KC_LT,  KC_GT,  KC_LCBR,KC_RCBR,                                    KC_0   ,KC_1,   KC_2,   KC_3,   KC_PEQL,  _______,
                                _______,_______,_______,                 _______,  MO(L_ADJUST),_______),

	[L_RAISE] = LAYOUT_split_3x6_3(
VIM_ESC,_______,_______,_______,_______,_______,                                 _______,_______,_______,_______,_______,KC_PGUP,
_______,_______,_______,_______,_______,_______,                                 KC_LEFT,KC_DOWN,  KC_UP,KC_RGHT,KC_HOME, KC_END,
_______,_______,_______,_______,_______,_______,                                 _______,_______,_______,_______,_______,KC_PGDN,
                                _______,  MO(L_ADJUST),_______,          _______,_______,_______),

	[L_ADJUST] = LAYOUT_split_3x6_3(
  RESET,  DF(1),  DF(0),  KC_NO,  KC_NO,  AG_TOGG,                                   KC_NO,  KC_NO,    KC_NO,    KC_NO,    KC_VOLU,  KC_NUM,
RGB_TOG,RGB_HUI,RGB_SAI,RGB_VAI,  KC_NO,  KC_NO,                                   KC_NO,  KC_NO,    KC_NO,    KC_NO,    KC_MUTE,  KC_CAPS,
RGB_MOD,RGB_HUD,RGB_SAD,RGB_VAD,  KC_NO,  NK_TOGG,                                   KC_NO,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_VOLD,  KC_SCRL,
                                KC_LGUI,_______, KC_SPC,                  KC_ENT,_______,KC_RALT),

	[L_VIM] = LAYOUT_split_3x6_3(
_______,_______,_______,_______,_______,_______,                                 _______,_______,_______,_______,_______,_______,
_______,_______,_______,_______,_______,_______,                                 _______,_______,_______,_______,_______,_______,
_______,_______,_______,_______,_______,_______,                                 _______,_______,_______,_______,_______,_______,
                                _______,LT(L_LOWER,KC_TAB),_______,                 _______,_______,_______),
};
// clang-format on

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    }
    return OLED_ROTATION_180;
}

void render_logo(void) {
    static const char PROGMEM logo[] = {// 'logo', 128x32px
                                        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xf0, 0x38, 0x0c, 0x06, 0x06, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x02, 0x06, 0x0c, 0x1c, 0x38, 0x20, 0x20, 0x20, 0x20, 0x60, 0x60, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x60, 0x30, 0x18, 0x18, 0x0f, 0x0d, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0x60, 0x30, 0x18, 0x0c, 0x04, 0x0c, 0x18, 0x30, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x07, 0x06, 0x06, 0x04, 0x0c, 0x0c, 0x18, 0x30, 0xe0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x7f, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x03, 0x82, 0xc6, 0x64, 0x3c, 0x18, 0x08, 0x80, 0xc1, 0xe3, 0x76, 0x1c, 0x0c, 0x4c, 0x4c, 0x48, 0x08, 0x38, 0xf0, 0xf8, 0x18, 0x08, 0x4c, 0x4c, 0x4f, 0xff, 0xfc, 0x06, 0x02, 0xce, 0xcc, 0x78, 0xe8, 0x08, 0x18, 0xf0, 0x78, 0x08, 0x88, 0xf8, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x03, 0x02, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x1e, 0x1e, 0x16, 0x13, 0x11, 0x10, 0x10, 0x10, 0x10, 0x10, 0x11, 0x13, 0x17, 0x16, 0x18, 0x18, 0x12, 0x12, 0x13, 0x19, 0x0f, 0x0f, 0x0f, 0x19, 0x13, 0x12, 0x10, 0x18, 0x0d, 0x0f, 0x18, 0x18, 0x13, 0x1b, 0x1e, 0xf9, 0x9f, 0xcc, 0x40, 0x60, 0x3c, 0x0f, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
    oled_write_raw_P(logo, sizeof(logo));
}

void render_host_led_state(void) {
    uint8_t leds = host_keyboard_leds();
    // FIXME: Better rewrite when space is finished
    oled_write_P((leds & (1 << USB_LED_NUM_LOCK)) ? PSTR("NL:on") : PSTR("NL:- "), false);
    oled_write_P((leds & (1 << USB_LED_CAPS_LOCK)) ? PSTR("CL:on") : PSTR("CL:- "), false);
    oled_write_P((leds & (1 << USB_LED_SCROLL_LOCK)) ? PSTR("SL:on") : PSTR("SL:- "), false);
    oled_write_P(keymap_config.nkro ? PSTR("NK:on") : PSTR("NK:- "), false);
    /* oled_write_P(get_autoshift_state() ? PSTR("AS:on") : PSTR("AS:- "), false); */
}

void oled_render_layer_state(void) {
    oled_write_P(PSTR("LYER:"), false);
    switch (get_highest_layer(layer_state)) {
        case L_BASE:
        case L_DVORAK:
            if (layer_state_cmp(default_layer_state, L_BASE)) {
                oled_write_ln_P(PSTR("QWER"), false);
            } else if (layer_state_cmp(default_layer_state, L_DVORAK)) {
                oled_write_ln_P(PSTR("DVOR"), false);
            }
            break;
        case L_LOWER:
            oled_write_ln_P(PSTR("LOWR"), false);
            break;
        case L_RAISE:
            oled_write_ln_P(PSTR("HIGR"), false);
            break;
        case L_ADJUST:
            oled_write_ln_P(PSTR("AJST"), false);
            break;
        case L_VIM:
            oled_write_ln_P(PSTR("VIM"), false);
            break;
    }
    oled_write_ln_P(PSTR(""), false);
}

void oled_render_led_state(void) { render_host_led_state(); }

void oled_render_os(void) { oled_write_ln_P(keymap_config.swap_lalt_lgui ? PSTR("GUI:R") : PSTR("GUI:L"), false); }

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_layer_state();
        oled_render_os();
        oled_render_led_state();
    } else {
        render_logo();
    }

    return false;
}

#endif  // OLED_ENABLE

void rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    HSV hsv;
    if (layer_state_is(L_DVORAK)) {
        hsv.h = 30;
        hsv.s = 255;
        hsv.v = 204;
    } else if (layer_state_is(L_VIM)) {
        hsv.h = 14;
        hsv.s = 255;
        hsv.v = 204;
    } else if (layer_state_is(L_ADJUST)) {
        hsv.h = 220;
        hsv.s = 255;
        hsv.v = 255;
    } else if (layer_state_is(L_RAISE)) {
        hsv.h = 109;
        hsv.s = 255;
        hsv.v = 255;
    } else if (layer_state_is(L_LOWER)) {
        hsv.h = 1;
        hsv.s = 255;
        hsv.v = 255;
    } else {
        hsv.h = 184;
        hsv.s = 255;
        hsv.v = 255;
    }

    if (hsv.v > rgb_matrix_get_val()) {
        hsv.v = rgb_matrix_get_val();
    }
    RGB rgb = hsv_to_rgb(hsv);

    for (uint8_t i = led_min; i <= led_max; i++) {
        if (HAS_FLAGS(g_led_config.flags[i], 0x02)) {  // 0x01 == LED_FLAG_MODIFIER
            rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
        }
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    bool vim_mode = handle_vim_mode(keycode, record, L_VIM, L_RAISE);
    switch (keycode) {
            //     This theorethically fixes shift delay when using shifted keys
            /* case QK_MODS ... QK_MODS_MAX: */
            /*     if (record->event.pressed) { */
            /*         tap_code16(keycode); */
            /*     } */
            /*     return false; */
        case LT(L_RAISE, KC_ENT) || LT(L_LOWER, KC_TAB):
            // Force to allow R/L in VIM mode
            // FIXME: Doesn't work :(
            return true;
        default:
            if (vim_mode) return false;
            return process_caps_word(keycode, record);
    }
}

void caps_word_set_user(bool active) {
#ifdef OLED_ENABLE
    if (active) {
        oled_write_P(PSTR("CW:on"), false);
    } else {
        oled_write_P(PSTR("CW:- "), false);
    }
#endif
}
