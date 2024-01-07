/*
Copyright 2022 aki27

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
#include <stdio.h>
#include "quantum.h"


// Defines names for use in layer keycodes and the keymap
enum layer_number {
    _BASE = 0,
    _LOWER = 1,
    _RAISE = 2,
    _TRACKBALL = 3,
    _Layer4 = 4,
    _Layer5 = 5,
    _Layer6 = 6
};


#define LW_SPC LT(1,KC_SPC) // lower
#define RS_ENT LT(2,KC_ENT) // raise
#define LGUI_LNG2 LGUI_T(KC_LNG2)
#define RGUI_LNG1 RGUI_T(KC_LNG1)
#define DEL_ALT ALT_T(KC_DEL)

#define CPI_SW QK_USER_0
#define SCRL_SW QK_USER_1
#define ROT_R15 QK_USER_2
#define ROT_L15 QK_USER_3
#define SCRL_MO QK_USER_4
#define SCRL_TO QK_USER_5
#define SCRL_IN QK_USER_6

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT(
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
       KC_ESC,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                          KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_MINS,
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
      KC_LCTL,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                                          KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                                          KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, RSFT_T(KC_EQL),
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
                        CM_TOGG, DEL_ALT,  LGUI_LNG2, LW_SPC, KC_MS_BTN1,             KC_MS_BTN2,  RS_ENT, RGUI_LNG1, DEL_ALT,  KC_BSPC,
                                                                 KC_PGUP, KC_MS_BTN3,  KC_PGDN, XXXXXXX, XXXXXXX, XXXXXXX
                                                            //`--------------'  `--------------'
    ),
  [_LOWER] = LAYOUT(
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
      KC_ESC,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                                       KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
      KC_LCTL, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                          KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_QUOT,
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
      KC_LSFT, KC_GRV,  KC_TILD, KC_NUBS, KC_PIPE, KC_LBRC,                                       KC_RBRC, KC_PLUS, KC_LABK, KC_RABK, KC_QUES, KC_UNDS,
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
                        KC_LGUI, DEL_ALT, KC_TRNS, KC_SPC,   KC_MS_BTN4,             KC_MS_BTN5,  TT(3), RGUI_LNG1, DEL_ALT,  KC_BSPC,
                                                                 KC_PGUP, KC_MS_BTN3,  KC_PGDN, XXXXXXX, XXXXXXX, XXXXXXX
                                                            //`--------------'  `--------------'
    ),
  [_RAISE] = LAYOUT(
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
      KC_F1,    KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                                        KC_F7,    KC_F8,   KC_F9,   KC_F10,   KC_F11,  KC_F12,
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
      KC_LCTL,  KC_PGDN, KC_PGUP, KC_HOME, KC_END,  KC_BSLS,                                      KC_LEFT,   KC_DOWN, KC_UP, KC_RGHT, KC_DQUO, KC_COLN,
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
      KC_LSFT,  KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_LBRC,                                      KC_RBRC, KC_DOWN, KC_RGHT,  KC_DOT, KC_SLSH, KC_MINS,
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
                        KC_LGUI, DEL_ALT, LGUI_LNG2,  TT(3), KC_MS_BTN4,             KC_MS_BTN5,  KC_ENT, KC_TRNS, KC_BSPC,  KC_ESC,
                                                                 KC_PGUP, KC_MS_BTN3,  KC_PGDN, XXXXXXX, XXXXXXX, XXXXXXX
                                                            //`--------------'  `--------------'
    ),
  [_TRACKBALL] = LAYOUT(
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_TOG,                                       SCRL_TO,  CPI_SW, SCRL_SW, ROT_L15, ROT_R15, XXXXXXX,
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
      XXXXXXX, XXXXXXX, RGB_VAI, RGB_SAI, RGB_HUI, RGB_MOD,                                       SCRL_MO, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
      XXXXXXX, XXXXXXX, RGB_VAD, RGB_SAD, RGB_HUD,RGB_RMOD,                                       SCRL_IN, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
                        KC_LGUI, DEL_ALT, KC_TRNS,  KC_SPC,   KC_MS_BTN1,             KC_MS_BTN2,  KC_ENT, KC_RGUI, KC_BSPC,  KC_ESC,
                                                                 KC_PGUP, KC_MS_BTN3,  KC_PGDN, XXXXXXX, XXXXXXX, XXXXXXX
                                                            //`--------------'  `--------------'
    ),
  [_Layer4] = LAYOUT(
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
                        XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,   XXXXXXX,             XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,
                                                                 XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
                                                            //`--------------'  `--------------'
    ),
  [_Layer5] = LAYOUT(
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
                        XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,   XXXXXXX,             XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,
                                                                 XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
                                                            //`--------------'  `--------------'
    ),
  [_Layer6] = LAYOUT(
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
                        XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,   XXXXXXX,             XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,
                                                                 XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
                                                            //`--------------'  `--------------'
    )
};

keyevent_t encoder1_ccw = {
    .key = (keypos_t){.row = 4, .col = 2},
    .pressed = false
};

keyevent_t encoder1_cw = {
    .key = (keypos_t){.row = 4, .col = 5},
    .pressed = false
};

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { /* First encoder */
        if (clockwise) {
            encoder1_cw.pressed = true;
            encoder1_cw.time = (timer_read() | 1);
            action_exec(encoder1_cw);
        } else {
            encoder1_ccw.pressed = true;
            encoder1_ccw.time = (timer_read() | 1);
            action_exec(encoder1_ccw);
        }
    }
    return true;
}


void matrix_scan_user(void) {
    if (IS_EVENT(encoder1_ccw) && encoder1_ccw.pressed) {
        encoder1_ccw.pressed = false;
        encoder1_ccw.time = (timer_read() | 1);
        action_exec(encoder1_ccw);
    }

    if (IS_EVENT(encoder1_cw) && encoder1_cw.pressed) {
        encoder1_cw.pressed = false;
        encoder1_cw.time = (timer_read() | 1);
        action_exec(encoder1_cw);
    }
}

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
    case _LOWER:
        cocot_set_scroll_mode(true);
        break;
    case _RAISE:
        cocot_set_scroll_mode(true);
        break;
    case _TRACKBALL:
        cocot_set_scroll_mode(false);
        break;
    case _Layer4:
        cocot_set_scroll_mode(false);
        break;
    case _Layer5:
        cocot_set_scroll_mode(false);
        break;
    case _Layer6:
        cocot_set_scroll_mode(false);
        break;
    default:
        cocot_set_scroll_mode(false);
        break;
    }
    return state;
};


#ifdef OLED_ENABLE
bool oled_task_user(void) {
    render_logo();
    oled_write_layer_state();
    return false;
}
#endif

#ifdef COMBO_ENABLE
const uint16_t PROGMEM combo_bs1[] = {KC_LCTL, KC_H, COMBO_END};
const uint16_t PROGMEM combo_bs2[] = {KC_O, KC_P, COMBO_END};
const uint16_t PROGMEM combo_grave[] = {KC_P, KC_MINS, COMBO_END};
const uint16_t PROGMEM combo_tab[] = {KC_A, KC_S, COMBO_END};
const uint16_t PROGMEM combo_home[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM combo_end[] = {KC_Z, KC_X, COMBO_END};
combo_t key_combos[] = {
    COMBO(combo_bs1, KC_BSPC),
    COMBO(combo_bs2, KC_BSPC),
    COMBO(combo_grave, KC_GRAVE),
    COMBO(combo_tab, KC_TAB),
    COMBO(combo_home, KC_HOME),
    COMBO(combo_end, KC_END),
};
#endif
