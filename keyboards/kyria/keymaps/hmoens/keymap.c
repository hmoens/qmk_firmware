/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
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
#include QMK_KEYBOARD_H
#include "features/casemodes.h"

enum layers {
    _QWERTY = 0,
    _SYMBOL,
    _NAV,
    _NUM
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Base Layer: QWERTY
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * | ESC    |   Q  |   W  |   E  |   R  |   T  |                              |   Y  |   U  |   I  |   O  |   P  |  BS    |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * | GUI/Tab|   A  |   S  |   D  |   F  |   G  |                              |   H  |   J  |   K  |   L  |  ; : |  ' "   |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  | NAV  | NAV  |  | NAV  | NAV  |   N  |   M  | ,  < | . >  | /  ? | RShift |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        | Ctrl |  Alt |  NUM | S/Spc| Enter|  | Enter| S/Spc|  NUM | AltGr| Ctrl |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_QWERTY] = LAYOUT(
      KC_ESC,                  KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,                                                                                   KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,    KC_BSPC,
      LGUI_T(KC_TAB),          KC_A,   KC_S,   KC_D,   KC_F,   KC_G,                                                                                   KC_H,    KC_J,    KC_K,    KC_L,   KC_SCLN, KC_QUOT,
      TD(TD_LSFT_CAPS),        KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,     TG(_NAV),            TG(_NAV),          TG(_NAV),          TG(_NAV),          KC_N,    KC_M,    KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
                                            KC_LCTRL, KC_LALT, TT(_NUM), LT(_SYMBOL, KC_SPC), LT(_NAV, KC_ENT),  LT(_NAV, KC_ENT),  LT(_SYMBOL, KC_SPC), TT(_NUM), KC_RALT, KC_RCTRL
    ),
/*
 * Lower Layer: Symbols
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |  !   |  @   |  {   |  }   |  |   |                              |   €  |  _   |  "   |  '   |  %   |   Del  |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |  #   |  $   |  (   |  )   |  `   |                              |   +  |  -   |  /   |  *   |  :   |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |  %   |  ^   |  [   |  ]   |  ~   |      |      |  |      |      |   &  |  =   |  <   |  >   |  ?   |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_SYMBOL] = LAYOUT(
      _______, KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_PIPE,                                     RALT(KC_5), KC_UNDS, KC_DQT,  KC_QUOT, KC_PERC, KC_DEL,
      _______, KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_GRV,                                      KC_PLUS, KC_MINS, KC_SLSH, KC_ASTR, KC_COLN, _______,
      _______, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD, _______, _______, _______, _______, KC_AMPR, KC_EQL,  KC_LT,   KC_GT,   KC_QUES, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
/*
 * Layer template
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |      |      |      |                              |      |   ü  |   ú  |   ï  |  ö   |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |                              |      |      |   é  |   í  |  ó   |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |   ì  |  ò   |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
//     [_UNICODE] = LAYOUT(
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
//     ),
/*
 * Navigation Layer
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |      |      |      |                              |      |CLeft |      |      |CRight|        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |                              |      | Left | Down | Up   | Right|        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |  Cut | Copy | Paste|      |      |      |  |      |      |      | PGUP | Home | End  | PGDWN|        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_NAV] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                                     _______, C(KC_LEFT), _______, _______, C(KC_RIGHT), _______,
      _______, _______, _______, _______, _______, _______,                                     _______, KC_LEFT,    KC_DOWN, KC_UP,   KC_RGHT,     _______,
      _______, _______, C(KC_X), C(KC_C), C(KC_V), _______, _______, _______, _______, _______, _______, KC_PGUP,    KC_HOME, KC_END,  KC_PGDN,     _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______,    _______, _______
    ),
/*
 * Num/FN
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        | F1   |  F2  | F3   | F4   | F5   |                              | F6   | F7   |  F8  | F9   | F10  |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |   1  |  2   |  3   |  4   |  5   |                              |  6   |  7   |  8   |  9   |  0   |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        | F11  | F12  | VolUp| VolDn| Play |      |      |  |      |      | PrScr| PrWin|PrRect|      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_NUM] = LAYOUT(
      _______, KC_F1,   KC_F2,  KC_F3,   KC_F4,   KC_F5,                                        KC_F6,   KC_F7,      KC_F8,      KC_F9,   KC_F10,  _______,
      _______, KC_1, 	KC_2,   KC_3,    KC_4,    KC_5,                                         KC_6,    KC_7,       KC_8,       KC_9,    KC_0,    _______,
      _______, KC_F11 , KC_F12, KC_VOLU, KC_VOLD, KC_MPLY,  _______, _______, _______, _______, KC_PSCR, A(KC_PSCR), S(KC_PSCR), _______, _______, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
// /*
//  * Layer template
//  *
//  * ,-------------------------------------------.                              ,-------------------------------------------.
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        `----------------------------------'  `----------------------------------'
//  */
//     [_LAYERINDEX] = LAYOUT(
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
//     ),
};

enum custom_keycodes {
    CAPSWORD = SAFE_RANGE,
    SNAKECASE,
    CAPSNAKECASE,
    CAMELCASE,
    TD_LSFT_CAPS,
};

/* MACROS */
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // Process case modes
    if (!process_case_modes(keycode, record)) {
        return false;
    }
    // Regular user keycode case statement
    switch (keycode) {
        case CAPSWORD:
            if (record->event.pressed) {
                enable_caps_word();
            }
            return false;
        case SNAKECASE:
            if (record->event.pressed) {
                enable_xcase_with(KC_UNDS);
            }
            return false;
        case CAPSNAKECASE:
            if (record->event.pressed) {
                enable_caps_word();
                enable_xcase_with(KC_UNDS);
            }
            return false;
        case CAMELCASE:
            if (record->event.pressed) {
                enable_xcase_with(OSM(MOD_LSFT))
            }
            return false;
        default:
            return true;
    }
}

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_LSFT_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS),
};
// TD(TD_LSFT_CAPS)
// LSFT_T(KC_CAPS)

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
	return OLED_ROTATION_180;
}

uint8_t last_highest_layer = -1;

void oled_task_user(void) {
    uint8_t highest_layer = get_highest_layer(layer_state);
    if (highest_layer != last_highest_layer) {
        last_highest_layer = highest_layer;
        oled_clear();
        switch (highest_layer) {
            case _QWERTY:
                break;
            case _SYMBOL:
                oled_write_P(PSTR("Layer: Symbol\n\n"), false);
                if (is_keyboard_left()) {
                    oled_write_P(PSTR("!  @  {  }  |\n\n"), false);
                    oled_write_P(PSTR("#  $  (  )  `\n\n"), false);
                    oled_write_P(PSTR("%  ^  [  ]  ~\n\n"), false);
                } else {
                    oled_write_P(PSTR("E  _  \"  '  %\n\n"), false);
                    oled_write_P(PSTR("+  -  /  *  :\n\n"), false);
                    oled_write_P(PSTR("&  =  <  >  ?\n\n"), false);
                }

                break;
            case _NAV:
                oled_write_P(PSTR("Layer: Navigation\n"), false);
                break;
            case _NUM:
                oled_write_P(PSTR("Layer: Num / FN\n"), false);
                break;
            default:
                oled_write_P(PSTR("Layer: Undefined\n"), false);
        }

        // Host Keyboard LED Status
        uint8_t led_usb_state = host_keyboard_leds();
        oled_write_P(IS_LED_ON(led_usb_state, USB_LED_NUM_LOCK) ? PSTR("NUMLCK ") : PSTR("       "), false);
        oled_write_P(IS_LED_ON(led_usb_state, USB_LED_CAPS_LOCK) ? PSTR("CAPLCK ") : PSTR("       "), false);
        oled_write_P(IS_LED_ON(led_usb_state, USB_LED_SCROLL_LOCK) ? PSTR("SCRLCK ") : PSTR("       "), false);
    }
}
#endif

#ifdef ENCODER_ENABLE
void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        // Volume control
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    else if (index == 1) {
        // Page up/Page down
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    }
}
#endif
