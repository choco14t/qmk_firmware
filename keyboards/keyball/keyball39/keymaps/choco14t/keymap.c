/*
Copyright 2022 @Yowkees
Copyright 2022 MURAOKA Taro (aka KoRoN, @kaoriya)

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

#include "quantum.h"

enum macro_keycodes {
    YB_FCUS_W = SAFE_RANGE, // yabai -m window --focus west
    YB_FCUS_S,              // yabai -m window --focus south
    YB_FCUS_N,              // yabai -m window --focus north
    YB_FCUS_E               // yabai -m window --focus east
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // keymap for default
  [0] = LAYOUT_universal(
    KC_Q     , KC_W     , KC_E     , KC_R     , KC_T     ,                            KC_Y     , KC_U     , KC_I     , KC_O     , KC_P     ,
    KC_A     , KC_S     , KC_D     , KC_F     , LGUI_T(KC_G)     ,                    KC_H     , KC_J     , KC_K     , KC_L     , RCTL_T(KC_SCLN)  ,
 LSFT_T(KC_Z),LCTL_T(KC_X), KC_C     , KC_V     , KC_B     ,                            KC_N     , KC_M     , RGUI_T(KC_COMM)  , LT(3,KC_DOT)   , RSFT_T(KC_SLSH)  ,
    KC_LALT  , KC_LGUI  , KC_LCTL  ,LSFT_T(KC_LNG2),LT(1,KC_SPC),LT(3,KC_LNG1),KC_BSPC,LT(2,KC_ENT),LSFT_T(KC_LNG2),KC_NO,KC_NO, KC_RALT
  ),

  [1] = LAYOUT_universal(
    KC_1     , KC_2     , KC_3     , KC_4     , KC_5     ,                            KC_6   , KC_7     , KC_8     , KC_9     , KC_0,
    KC_F5    , KC_EXLM  , S(KC_6)  , KC_BSLS  , KC_LBRC  ,                            KC_RBRC, KC_BTN1  , KC_BTN3  , KC_BTN2  , RCTL_T(KC_QUOT),
    S(KC_EQL),S(KC_LBRC), S(KC_7)  , KC_EQL   , KC_GRV   ,                            KC_MINS, KC_BTN4  , KC_PGDN  , KC_BTN5  , _______,
    KC_LSFT  , KC_EQL   , KC_LCTL  , _______  , _______  , _______  ,      _______   ,_______, _______  , KC_NO    , KC_NO    , _______
  ),

  [2] = LAYOUT_universal(
    KC_F1    , KC_F2    , KC_F3    , KC_F4    , KC_F5    ,                              KC_F6  , KC_F7    , KC_F8    , KC_F9    , KC_F10,
    KC_ESC   , KC_HOME  , KC_END   , KC_F11   , KC_F12   ,                              KC_LEFT, KC_DOWN  , KC_UP    , KC_RGHT  , S(KC_QUOT),
    KC_TAB   , KC_1     , KC_2     , S(KC_EQL), S(KC_GRV),                         S(KC_MINS), KC_PGDN  , KC_PGUP  , _______  , _______,
    KC_LALT  , KC_NO    , KC_NO    , KC_LGUI  , LGUI_T(KC_SPC),KC_LCTL,      _______  , _______, _______  , _______  , _______  , KC_RGUI
  ),

  [3] = LAYOUT_universal(
    RGB_TOG  , AML_TO   , AML_I50  , AML_D50  , _______  ,                            S(KC_Y)  , _______  , SSNP_HOR , SSNP_VRT , SSNP_FRE ,
    RGB_MOD  , SSNP_VRT , SSNP_HOR , SSNP_FRE , SCRL_DVI ,                            YB_FCUS_W, YB_FCUS_S  , YB_FCUS_N  , YB_FCUS_E  , _______  ,
    CPI_D1K  , CPI_D100 , CPI_I100 , CPI_I1K  , SCRL_DVD ,                            CPI_D1K  , CPI_D100 , CPI_I100 , CPI_I1K  , KBC_SAVE ,
    QK_BOOT  , KBC_RST  , _______  , _______  , _______  , _______  ,      _______  , _______  , _______  , _______  , KBC_RST  , QK_BOOT
  ),
};
// clang-format on

layer_state_t layer_state_set_user(layer_state_t state) {
    // Auto enable scroll mode when the highest layer is 3
    keyball_set_scroll_mode(get_highest_layer(state) == 3);
    return state;
}

#ifdef OLED_ENABLE

#    include "lib/oledkit/oledkit.h"

void oledkit_render_info_user(void) {
    keyball_oled_render_keyinfo();
    keyball_oled_render_ballinfo();
    keyball_oled_render_layerinfo();
}
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case YB_FCUS_W:
            if (record->event.pressed) {
                register_code(KC_LALT);
                register_code(KC_LCTL);
                register_code(KC_H);
            } else {
                unregister_code(KC_H);
                unregister_code(KC_LCTL);
                unregister_code(KC_LALT);
            }
            break;
        case YB_FCUS_S:
            if (record->event.pressed) {
                register_code(KC_LALT);
                register_code(KC_LCTL);
                register_code(KC_J);
            } else {
                unregister_code(KC_J);
                unregister_code(KC_LCTL);
                unregister_code(KC_LALT);
            }
            break;
        case YB_FCUS_N:
            if (record->event.pressed) {
                register_code(KC_LALT);
                register_code(KC_LCTL);
                register_code(KC_K);
            } else {
                unregister_code(KC_K);
                unregister_code(KC_LCTL);
                unregister_code(KC_LALT);
            }
            break;
        case YB_FCUS_E:
            if (record->event.pressed) {
                register_code(KC_LALT);
                register_code(KC_LCTL);
                register_code(KC_L);
            } else {
                unregister_code(KC_L);
                unregister_code(KC_LCTL);
                unregister_code(KC_LALT);
            }
            break;
        default:
            return true;
    }
    return true;
}
