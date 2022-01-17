#include QMK_KEYBOARD_H
//#define SWE_AA LALT(KC_A)
#ifndef VIMMOD_H
#define VIMMOD_H

#define L_SHIFT_HELD (get_mods() & (MOD_BIT(KC_LSFT)))
#define R_SHIFT_HELD (get_mods() & (MOD_BIT(KC_RSFT)))
#define SHIFT_HELD (L_SHIFT_HELD || R_SHIFT_HELD)
#define L_CTRL_HELD (get_mods() & (MOD_BIT(KC_LCTRL)))
#define R_CTRL_HELD (get_mods() & (MOD_BIT(KC_RCTRL)))
#define CTRL_HELD (L_CTRL_HELD || R_CTRL_HELD)
#define L_GUI_HELD (get_mods() & (MOD_BIT(KC_LGUI)))
#define R_GUI_HELD (get_mods() & (MOD_BIT(KC_RGUI)))
#define GUI_HELD (L_GUI_HELD || R_GUI_HELD)

#ifndef TAPPING_TERM
#  define TAPPING_TERM 250
#endif

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
  VIM_ESC = SAFE_RANGE,
};

bool handle_vim_mode(uint16_t keycode, keyrecord_t *record, uint8_t vim_layer_no, uint8_t base_layer_no);
void mod_type(uint16_t modcode, uint16_t keycode);
#endif
