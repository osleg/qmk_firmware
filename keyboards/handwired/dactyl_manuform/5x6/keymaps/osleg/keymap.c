#include QMK_KEYBOARD_H
#include "string.h"
#include "split_util.h"
#include "quantum.h"
#include "raw_hid.h"


#define _QWERTY 0
#define _DVORAK 1
#define _ADJUST 2
#define _FNISH 3

#define RAISE MO(_FNish)
#define LOWER MO(_ADJUST)



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_QWERTY] = LAYOUT_5x6(
 KC_GRV,   KC_1,   KC_2,   KC_3,   KC_4,   KC_5,                                    KC_6,   KC_7,   KC_8,   KC_9,   KC_0, KC_EQL,
 KC_ESC,   KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,                                    KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,KC_BSLS,
KC_LCTL,   KC_A,   KC_S,   KC_D,   KC_F,   KC_G,                                    KC_H,   KC_J,   KC_K,   KC_L,KC_SCLN,KC_QUOT,
KC_LSPO,   KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,                                    KC_N,   KC_M,KC_COMM, KC_DOT,KC_SLSH,KC_RSPC,
           KC_LT,  KC_GT,                                                                        KC_PLUS,KC_MINS,
                     LT(2,KC_TAB), KC_SPC,                                        KC_BSPC,LT(3,KC_ENT),
                                         KC_LALT,KC_LGUI,        KC_APP, KC_DEL,
                                         KC_LBRC,KC_LCBR,        KC_RCBR,KC_RBRC),
	[_DVORAK] = LAYOUT_5x6(
 KC_GRV,   KC_1,   KC_2,   KC_3,   KC_4,   KC_5,                                    KC_6,   KC_7,   KC_8,   KC_9,   KC_0, KC_EQL,
 KC_ESC,KC_QUOT,KC_COMM, KC_DOT,   KC_P,   KC_Y,                                    KC_F,   KC_G,   KC_C,   KC_R,   KC_L,KC_BSLS,
KC_LCTL,   KC_A,   KC_O,   KC_E,   KC_U,   KC_I,                                    KC_D,   KC_H,   KC_T,   KC_N,   KC_S,KC_SLSH,
KC_LSPO,KC_SCLN,   KC_Q,   KC_J,   KC_K,   KC_X,                                    KC_B,   KC_M,   KC_W,   KC_V,   KC_Z,KC_RSPC,
           KC_LT,  KC_GT,                                                                        KC_PLUS,KC_MINS,
                     LT(2,KC_TAB), KC_SPC,                                        KC_BSPC,LT(3,KC_ENT),
                                         KC_LALT,KC_LGUI,        KC_APP, KC_DEL,
                                         KC_LBRC,KC_LCBR,        KC_RCBR,KC_RBRC),
	[_ADJUST] = LAYOUT_5x6(
KC_TILD,_______,_______,_______,_______,_______,                                 _______,_______,_______,_______,_______,_______,
_______,KC_EXLM,  KC_AT,KC_HASH, KC_DLR,KC_PERC,                                  KC_INS,  KC_P7,  KC_P8,  KC_P9,KC_MINS,KC_PGUP,
_______,KC_CIRC,KC_AMPR,KC_ASTR,KC_LBRC,KC_RBRC,                                 KC_HOME,  KC_P4,  KC_P5,  KC_P6,KC_PLUS, KC_END,
_______,KC_BSLS,KC_UNDS,KC_SLSH,KC_LCBR,KC_RCBR,                                   KC_P0,  KC_P1,  KC_P2,  KC_P3, KC_EQL,KC_PGDN,
         _______,_______,                                                                        _______,_______,
                         _______,_______,                                        _______,_______,
                                         _______,_______,        _______,_______,
                                         _______,_______,        _______,_______),
	[_FNISH] = LAYOUT_5x6(
  KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,                                   KC_F7,  KC_F8,  KC_F9, KC_F10, KC_F11, KC_F12,
 KC_INS,KC_NLCK,_______,KC_PSCR,KC_SLCK,KC_PAUS,                                 _______,_______,_______,_______,RGB_MOD,RGB_TOG,
KC_CAPS,KC_MPRV,KC_MPLY,KC_MNXT,KC_HOME,KC_PGUP,                                 KC_LEFT,KC_DOWN,  KC_UP,KC_RGHT,RGB_RMOD,RGB_VAI,
_______,KC_MUTE,KC_VOLD,KC_VOLU, KC_END,KC_PGDN,                                 _______,_______,RGB_SAI,RGB_HUI,_______,RGB_VAD,
         _______,_______,                                                                        RGB_SAD,RGB_HUD,
                         _______,_______,                                        _______,_______,
                                           DF(1),  DF(0),        _______,VLK_TOG,
                                         _______,_______,        _______,NK_TOGG)
};


bool is_hid_connected = false;

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
   return OLED_ROTATION_90;
}

void write(char *prefix, const char *value) {
  oled_write(prefix, false);
  oled_write_ln(value, false);
}

bool oled_task_user(void) {
  if (is_keyboard_master()) {
    // Host Keyboard Layer Status
    oled_write_P(PSTR("LYER:"), false);
    if (layer_state_cmp(default_layer_state, 0)) {
      oled_write_ln_P(PSTR("QWRTY"), false);
    } else {
      oled_write_ln_P(PSTR("DVORK"), false);
    }

    switch (get_highest_layer(layer_state)) {
      case _ADJUST:
        oled_write_ln_P(PSTR("ADJST"), false); break; 
      case _FNISH:
        oled_write_ln_P(PSTR("FNish"), false);
        break;
      default:
        break;
    }
    // Host Keyboard LED Status
    led_t led_usb_state = host_keyboard_led_state(;
    oled_write(led_usb_state.num_lock ? "NUM\n" : "\n", false);
    oled_write(led_usb_state.scroll_lock ? "SCR\n" : "\n", false);
    oled_write(led_usb_state.caps_lock ? "CAPS\n" :"\n", false);
  } else {
    uint8_t h = rgblight_get_hue();
    uint8_t s = rgblight_get_sat();
    uint8_t v = rgblight_get_val();
    switch (rgblight_get_mode()) {
      case RGBLIGHT_MODE_STATIC_LIGHT:
        write("", "STATC");
        break;
      case RGBLIGHT_MODE_KNIGHT:
      case RGBLIGHT_MODE_KNIGHT+1:
      case RGBLIGHT_MODE_KNIGHT+2:
        write("", "KNIGT");
        break;
      case RGBLIGHT_MODE_RAINBOW_SWIRL:
      case RGBLIGHT_MODE_RAINBOW_SWIRL+1:
      case RGBLIGHT_MODE_RAINBOW_SWIRL+2:
      case RGBLIGHT_MODE_RAINBOW_SWIRL+3:
      case RGBLIGHT_MODE_RAINBOW_SWIRL+4:
      case RGBLIGHT_MODE_RAINBOW_SWIRL+5:
        write("", "SWIRL");
        break;
      case RGBLIGHT_MODE_TWINKLE:
      case RGBLIGHT_MODE_TWINKLE+1:
      case RGBLIGHT_MODE_TWINKLE+2:
      case RGBLIGHT_MODE_TWINKLE+3:
      case RGBLIGHT_MODE_TWINKLE+4:
      case RGBLIGHT_MODE_TWINKLE+5:
        write("", "TWNKL");
        break;
      default:
        break;
    }
    write("H:", get_u8_str(h, ' '));
    write("S:", get_u8_str(s, ' '));
    write("V:", get_u8_str(v, ' '));

  /*   if (is_hid_connected) { */
  /*       write("HD:", "y\n"); */
  /*   } else { */
  /*       write("HD:", "n\n"); */
  /*   } */
  /*   write("RO", get_u8_str(keymap_config.nkro, ' ')); */
  }
  return true;
}
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  /* uint8_t ss = 2; */
  /* for (int i = 0; i < ss; i++) { */
  /*   raw_hid_send((uint8_t *)(keycode >> (8 * i) & 0xFF), 32); */
  /* } */
  switch (keycode) {
      case QK_MODS ... QK_MODS_MAX:
          if (record->event.pressed) {
              tap_code16(keycode);
          }
          return false;
  }
  return true;
}

#ifdef HIDRAW_ENABLED
enum IncomeControl {
  _LayoutControl = 1,
  _RGBControl,
  _GetInfo
};

enum LayoutControlActions {
  _RaiseLayout = 1,
  _DefaultLayout,
};

void raw_hid_receive(uint8_t *data, uint8_t length) {
    /* uint8_t a = data[0]; */
    if (!is_hid_connected) is_hid_connected = true;
    // Check control
    switch (data[0])  {
    case _LayoutControl:
      // Control layout
      switch (data[1])  {
      case  _RaiseLayout:
        if (data[2] < 2) {
          break;
        }
        set_oneshot_layer(data[2], get_oneshot_layer_state());
        break;
      case _DefaultLayout:
        if (data[2] > 1) {
          break;
        }
        write("set", get_u8_str(data[2], ' '));
        default_layer_set(data[2]);
        break;
      default: break;
      }
      break;
    case _RGBControl:
      write("RGB", ":P");
      break;
    case _GetInfo:
      break;
    default: break;
    }
}
#endif
