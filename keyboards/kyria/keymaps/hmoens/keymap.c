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
    _NUM,
    _FN,
    _MACRO,
    _LOCK
};

enum custom_keycodes {
    CAPSWORD = SAFE_RANGE,
    SNAKECASE,
    CAPSNAKECASE,
    CAMELCASE,
    // TD_LSFT_CAPS,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Base Layer: QWERTY
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * | ESC/FN |   Q  |   W  |   E  |   R  |   T  |                              |   Y  |   U  |   I  |   O  |   P  |  BS    |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * | Tab/MAC| A/NUM| S/alt| D/ctl|   F  |   G  |                              |   H  |   J  | K/ctl| L/alt|;:/NUM|  ' "   |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |   GUI  |   Z  |   X  |   C  |   V  |   B  | Lock |      |  |      | Lock |   N  |   M  | ,  < | . >  | /  ? | RShift |
 * `----------------------+------+------+------+------+      |  |      +------+------+------+------+----------------------'
 *                        |  SH  |  Alt | Shift| S/Spc| Enter|  | Enter| S/Spc| Shift| AltGr|  SH  |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_QWERTY] = LAYOUT(
      LT(_FN, KC_ESC),         KC_Q,           KC_W,         KC_E,           KC_R,   KC_T,                                                                                       KC_Y,    KC_U,    KC_I,         KC_O,         KC_P,              KC_BSPC,
      LT(_MACRO, KC_TAB),      LT(_NUM, KC_A), LALT_T(KC_S), LCTL_T(KC_D),   KC_F,   KC_G,                                                                                       KC_H,    KC_J,    RCTL_T(KC_K), LALT_T(KC_L), LT(_NUM, KC_SCLN), KC_QUOT,
      KC_LGUI,                 KC_Z,           KC_X,         KC_C,           KC_V,   KC_B,         OSL(_LOCK),        KC_NO,             KC_NO,               OSL(_LOCK),        KC_N,    KC_M,    KC_COMM,      KC_DOT,       KC_SLSH,           KC_RGUI,
                                            SH_OS, KC_LALT,  KC_LSFT, LT(_SYMBOL, KC_SPC), LT(_NAV, KC_ENT),  LT(_NAV, KC_ENT),  LT(_SYMBOL, KC_SPC), KC_RSFT, KC_RALT, SH_OS
    ),
/*
 * Symbols layer
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |  !   |  @   |  {   |  }   |  `   |                              |   €  |  _   |  |   |  ~   |  %   |   Del  |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |  #   |  $   |  (   |  )   |  "   |                              |   +  |  -   |  /   |  *   |  :   |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |  %   |  ^   |  [   |  ]   |  '   | Ulock|      |  |      | Ulock|   &  |  =   |  \   |  >   |  ?   |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_SYMBOL] = LAYOUT(
      _______, KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_GRV,                                      RALT(KC_5), KC_UNDS, KC_PIPE,   KC_TILD, KC_PERC, KC_DEL,
      _______, KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_DQT,                                      KC_PLUS,    KC_MINS, KC_SLSH,   KC_ASTR, KC_COLN, _______,
      _______, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_QUOT, TO(0),   _______, _______, TO(0),   KC_AMPR,    KC_EQL,  KC_BSLASH, KC_GT,   KC_QUES, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
/*
 * Navigation Layer
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |CLeft |      |      |CRight|      |                              |      |CLeft |      |      |CRight|        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        | Left | Down | Up   | Right|      |                              |      | Left | Down | Up   | Right|        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        | PGUP | Home | End  | PGDWN|      | Ulock|      |  |      | Ulock|      | PGUP | Home | End  | PGDWN|        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_NAV] = LAYOUT(
      _______, C(KC_LEFT), KC_NO,   KC_NO, C(KC_RIGHT), KC_NO,                                        KC_NO, C(KC_LEFT), KC_NO,   KC_NO,  C(KC_RIGHT), _______,
      _______, KC_LEFT,    KC_DOWN, KC_UP,   KC_RGHT,   KC_NO,                                        KC_NO, KC_LEFT,    KC_DOWN, KC_UP,  KC_RGHT,     _______,
      _______, KC_PGUP,    KC_HOME, KC_END,  KC_PGDN,   KC_NO,    TO(0),   _______, _______, TO(0),   KC_NO, KC_PGUP,    KC_HOME, KC_END, KC_PGDN,     _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______
    ),
/*
 * Num
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |   .  |  7   |  8   |  9   |  +   |                              |  +   |  7   |  8   |  9   |  .   |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |   /  |  4   |  5   |  6   |  -   |                              |  -   |  4   |  5   |  6   |  /   |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |   *  |  1   |  2   |  3   |  0   | Ulock|      |  |      | Ulock|  0   |  1   |  2   |  3   |  *   |        |
 * `----------------------+------+------+------+------+------|  |------+------+------.+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_NUM] = LAYOUT(
      _______, KC_DOT,  KC_7, KC_8, KC_9, KC_PLUS,                                     KC_PLUS, KC_7, KC_8, KC_9, KC_DOT,  _______,
      _______, KC_SLSH, KC_4, KC_5, KC_6, KC_MINS,                                     KC_MINS, KC_4, KC_5, KC_6, KC_SLSH, _______,
      _______, KC_ASTR, KC_1, KC_2, KC_3, KC_0,    TO(0),   _______, _______, TO(0),   KC_0,    KC_1, KC_2, KC_3, KC_ASTR, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
/*
 * FN
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        | F1   |  F2  | F3   | F4   | F5   |                              | F6   | F7   |  F8  | F9   | F10  |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        | Mute | VolDn| VolUp| Play |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        | F11  | F12  | PrScr| PrWin|PrRect| Ulock|      |  |      | Ulock|      |      |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_FN] = LAYOUT(
      _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,      KC_F5,                                       KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
      _______, KC_MUTE, KC_VOLD, KC_VOLU, KC_MPLY,    KC_NO,                                       KC_NO,   _______, _______, _______, _______, _______,
      _______, KC_F11 , KC_F12,  KC_PSCR, A(KC_PSCR), S(KC_PSCR),  TO(0), _______, _______, TO(0), _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
/*
 * Macros
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        | CWRD | CmlCs|      |      |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        | sn_cs|      |      |      |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        | SN_CS|      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_MACRO] = LAYOUT(
      _______, CAPSWORD, CAMELCASE, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
      _______, SNAKECASE, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
      _______, CAPSNAKECASE, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
/*
 * Lock
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  _FN   |      |      |      |      |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        | _NUM |      |      |      |      |                              |      |      |      |      | _NUM |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      | _NAV |  | _NAV |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_LOCK] = LAYOUT(
      TO(_FN), KC_NO,    KC_NO, KC_NO, KC_NO, KC_NO,                                   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,    KC_NO,
      KC_NO,   TO(_NUM), KC_NO, KC_NO, KC_NO, KC_NO,                                   KC_NO, KC_NO, KC_NO, KC_NO, TO(_NUM), KC_NO,
      KC_NO,   KC_NO,    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,    KC_NO,    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,    KC_NO,
                                    KC_NO, KC_NO, KC_NO, TO(_NAV), TO(_NAV), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
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
                enable_xcase_with(OSM(MOD_LSFT));
            }
            return false;
        default:
            return true;
    }
}

// // Tap Dance definitions
// qk_tap_dance_action_t tap_dance_actions[] = {
//     [TD_LSFT_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS),
// };
// // TD(TD_LSFT_CAPS)
// // LSFT_T(KC_CAPS)

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
                    oled_write_P(PSTR("!  @  {  }  `\n\n"), false);
                    oled_write_P(PSTR("#  $  (  )  \"\n\n"), false);
                    oled_write_P(PSTR("%  ^  [  ]  '\n\n"), false);
                } else {
                    oled_write_P(PSTR("E  _  |  ~  %\n\n"), false);
                    oled_write_P(PSTR("+  -  /  *  :\n\n"), false);
                    oled_write_P(PSTR("&  =  \\  >  ?\n\n"), false);
                }

                break;
            case _NAV:
                oled_write_P(PSTR("Layer: nav\n\n"), false);
                oled_write_P(PSTR("<<<            >>>\n\n"), false);
                oled_write_P(PSTR(" <    _    ^    > \n\n"), false);
                oled_write_P(PSTR("PUP  HOM  END  PGD\n\n"), false);
                break;
            case _NUM:
                oled_write_P(PSTR("Layer: Num\n\n"), false);
                if (is_keyboard_left()) {
                    oled_write_P(PSTR(".  7  8  9  +\n\n"), false);
                    oled_write_P(PSTR("/  4  5  6  -\n\n"), false);
                    oled_write_P(PSTR("*  1  2  3  0\n\n"), false);
                } else {
                    oled_write_P(PSTR("+  7  8  9  .\n\n"), false);
                    oled_write_P(PSTR("-  4  5  6  /\n\n"), false);
                    oled_write_P(PSTR("0  1  2  3  *\n\n"), false);
                }
                break;
            case _FN:
                oled_write_P(PSTR("Layer: Fn\n"), false);
                if (is_keyboard_left()) {
                    oled_write_P(PSTR("F1   F2   F3   F4   F5\n\n"), false);
                    oled_write_P(PSTR("Mut  VDw  DUp  Ply  \n\n"), false);
                    oled_write_P(PSTR("F11  F12  PSc  PWn  PRe\n\n"), false);
                } else {
                    oled_write_P(PSTR("F6   F7   F8   F9   F10\n\n"), false);
                    oled_write_P(PSTR("\n\n"), false);
                    oled_write_P(PSTR("\n\n"), false);
                }
                break;
            case _MACRO:
                oled_write_P(PSTR("Layer: Macro\n"), false);
                break;
            case _LOCK:
                oled_write_P(PSTR("Layer: Lock\n"), false);
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
