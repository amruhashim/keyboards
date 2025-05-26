/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>
Modified 2025 for Cygnus V1 - Ergonomic Dactyl Manuform Layout

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
// qmk compile -kb crkbd -km cygnus_v1 -e CONVERT_TO=rp2040_ce -e EEPROM_CLEAR=yes
#include QMK_KEYBOARD_H

// Layer definitions
enum layer_names { _BASE = 0, _LOWER, _RAISE, _FUNCTION, _ADJUST };

// Custom keycodes
enum custom_keycodes {
    P_SPOTLIGHT = SAFE_RANGE,
    CTRL_H,
    CTRL_J,
    CTRL_K,
    CTRL_L,
    SYM_1, // ! normally, 1 when shifted
    SYM_2, // @ normally, 2 when shifted
    SYM_3, // # normally, 3 when shifted
    SYM_4, // $ normally, 4 when shifted
    SYM_5, // % normally, 5 when shifted
    SYM_6, // ^ normally, 6 when shifted
    SYM_7, // & normally, 7 when shifted
    SYM_8, // * normally, 8 when shifted
    SYM_9, // ( normally, 9 when shifted
    SYM_0, // ) normally, 0 when shifted
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // ============================================================================
    // BASE LAYER - QWERTY with Alt access and ergonomic improvements
    // Left thumb: TAB → SHIFT → ENTER | Right thumb: SPACE ← BACKSPACE ← CMD+ESC
    // P key: Tap for P, Hold for CMD+SPACE (Spotlight)
    // ============================================================================
    [_BASE] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        XXXXXXX, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, P_SPOTLIGHT, XXXXXXX,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        XXXXXXX, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, XXXXXXX,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        XXXXXXX, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, LALT_T(KC_SLSH), XXXXXXX,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
        LCTL_T(KC_TAB), KC_LSFT, LT(_LOWER, KC_ENT), LT(_RAISE, KC_SPC), KC_BSPC, LCMD_T(KC_ESC)
        //`--------------------------'  `--------------------------'
        ),

    // ============================================================================
    // LOWER LAYER - Numbers & Navigation for Coding
    // ============================================================================
    [_LOWER] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        XXXXXXX, KC_1, KC_2, KC_3, KC_4, KC_5, KC_MS_BTN1, KC_MS_WH_UP, KC_MS_BTN2, KC_DEL, KC_INS, XXXXXXX,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        XXXXXXX, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MS_LEFT, KC_MS_DOWN, KC_MS_UP, KC_MS_RIGHT, KC_PGUP, XXXXXXX,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        XXXXXXX, LCMD(KC_Z), LCMD(KC_X), LCMD(KC_C), LCMD(KC_V), LCMD(KC_B), KC_MS_BTN3, KC_MS_WH_DOWN, KC_HOME, KC_END, KC_PGDN, XXXXXXX,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
        KC_LCTL, KC_LSFT, _______, _______, KC_BSPC, KC_LCMD
        //`--------------------------'  `--------------------------'
        ),

    // ============================================================================
    // RAISE LAYER - Programming Symbols with Numbers on Shift
    // Top row: !@#$%^&*() - when shifted gives 1234567890
    // Punctuation: ,.;/ naturally shift to <>:? (NO duplicate symbols)
    // Backtick and tilde as separate keys in good positions
    // HJKL: Normal symbols, or arrow keys when Ctrl is held
    // ============================================================================
    [_RAISE] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        XXXXXXX, SYM_1, SYM_2, SYM_3, SYM_4, SYM_5, SYM_6, SYM_7, SYM_8, SYM_9, SYM_0, XXXXXXX,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        XXXXXXX, KC_EQL, KC_LBRC, KC_RBRC, KC_LPRN, KC_RPRN, CTRL_H, CTRL_J, CTRL_K, CTRL_L, KC_SCLN, XXXXXXX,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        XXXXXXX, KC_GRV, KC_BSLS, KC_PIPE, KC_TILD, KC_DQT, KC_PLUS, KC_COMM, KC_QUOT, KC_DOT, LALT_T(KC_SLSH), XXXXXXX,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
        LCTL_T(KC_TAB), KC_LSFT, MO(_ADJUST), _______, KC_BSPC, KC_LCMD
        //`--------------------------'  `--------------------------'
        ),

    // ============================================================================
    // FUNCTION LAYER - F-keys & Mac System Controls (Ergonomic Layout)
    // ============================================================================
    [_FUNCTION] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        XXXXXXX, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, XXXXXXX,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        XXXXXXX, KC_F11, KC_F12, KC_BRID, KC_BRIU, KC_MUTE, KC_VOLD, KC_VOLU, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, LCMD(LSFT(KC_3)), LCMD(LSFT(KC_4)), LCMD(LSFT(KC_5)), XXXXXXX,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
        KC_LCTL, XXXXXXX, XXXXXXX, KC_SPC, KC_BSPC, KC_LCMD
        //`--------------------------'  `--------------------------'
        ),

    // ============================================================================
    // ADJUST LAYER - System Controls and Keyboard Settings
    // ============================================================================
    [_ADJUST] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_SYSTEM_SLEEP, XXXXXXX,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, LCTL(LSFT(KC_PWR)), XXXXXXX,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
        TG(_FUNCTION), _______, XXXXXXX, KC_SPC, KC_BSPC, KC_RSFT
        //`--------------------------'  `--------------------------'
        )};

// ============================================================================
// Layer State Management
// ============================================================================
layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

// ============================================================================
// Key Combo Definitions (Optional - for advanced users)
// ============================================================================
#ifdef COMBO_ENABLE
const uint16_t PROGMEM combo_esc[]   = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM combo_tab[]   = {KC_A, KC_S, COMBO_END};
const uint16_t PROGMEM combo_enter[] = {KC_L, KC_SCLN, COMBO_END};

combo_t key_combos[] = {
    COMBO(combo_esc, KC_ESC),
    COMBO(combo_tab, KC_TAB),
    COMBO(combo_enter, KC_ENT),
};
#endif

// ============================================================================
// Custom Key Processing
// ============================================================================
static uint16_t p_spotlight_timer;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case P_SPOTLIGHT:
            if (record->event.pressed) {
                p_spotlight_timer = timer_read();
            } else {
                if (timer_elapsed(p_spotlight_timer) < TAPPING_TERM) {
                    // Tap: send P
                    tap_code(KC_P);
                } else {
                    // Hold: send CMD+SPACE
                    tap_code16(LCMD(KC_SPC));
                }
            }
            return false;

        // Symbol/Number keys - symbols by default, numbers when shifted
        case SYM_1:
            if (record->event.pressed) {
                if (get_mods() & MOD_MASK_SHIFT) {
                    tap_code(KC_1);
                } else {
                    tap_code16(KC_EXLM);
                }
            }
            return false;

        case SYM_2:
            if (record->event.pressed) {
                if (get_mods() & MOD_MASK_SHIFT) {
                    tap_code(KC_2);
                } else {
                    tap_code16(KC_AT);
                }
            }
            return false;

        case SYM_3:
            if (record->event.pressed) {
                if (get_mods() & MOD_MASK_SHIFT) {
                    tap_code(KC_3);
                } else {
                    tap_code16(KC_HASH);
                }
            }
            return false;

        case SYM_4:
            if (record->event.pressed) {
                if (get_mods() & MOD_MASK_SHIFT) {
                    tap_code(KC_4);
                } else {
                    tap_code16(KC_DLR);
                }
            }
            return false;

        case SYM_5:
            if (record->event.pressed) {
                if (get_mods() & MOD_MASK_SHIFT) {
                    tap_code(KC_5);
                } else {
                    tap_code16(KC_PERC);
                }
            }
            return false;

        case SYM_6:
            if (record->event.pressed) {
                if (get_mods() & MOD_MASK_SHIFT) {
                    tap_code(KC_6);
                } else {
                    tap_code16(KC_CIRC);
                }
            }
            return false;

        case SYM_7:
            if (record->event.pressed) {
                if (get_mods() & MOD_MASK_SHIFT) {
                    tap_code(KC_7);
                } else {
                    tap_code16(KC_AMPR);
                }
            }
            return false;

        case SYM_8:
            if (record->event.pressed) {
                if (get_mods() & MOD_MASK_SHIFT) {
                    tap_code(KC_8);
                } else {
                    tap_code16(KC_ASTR);
                }
            }
            return false;

        case SYM_9:
            if (record->event.pressed) {
                if (get_mods() & MOD_MASK_SHIFT) {
                    tap_code(KC_9);
                } else {
                    tap_code16(KC_LPRN);
                }
            }
            return false;

        case SYM_0:
            if (record->event.pressed) {
                if (get_mods() & MOD_MASK_SHIFT) {
                    tap_code(KC_0);
                } else {
                    tap_code16(KC_RPRN);
                }
            }
            return false;

        case CTRL_H:
            if (record->event.pressed) {
                if (get_mods() & MOD_MASK_CTRL) {
                    // Clear Ctrl modifier temporarily, send Left arrow, then restore
                    uint8_t mods = get_mods();
                    clear_mods();
                    tap_code(KC_LEFT);
                    set_mods(mods);
                } else {
                    // Otherwise send - (minus)
                    tap_code(KC_MINS);
                }
            }
            return false;

        case CTRL_J:
            if (record->event.pressed) {
                if (get_mods() & MOD_MASK_CTRL) {
                    // Clear Ctrl modifier temporarily, send Down arrow, then restore
                    uint8_t mods = get_mods();
                    clear_mods();
                    tap_code(KC_DOWN);
                    set_mods(mods);
                } else {
                    // Otherwise send _ (underscore)
                    tap_code16(KC_UNDS);
                }
            }
            return false;

        case CTRL_K:
            if (record->event.pressed) {
                if (get_mods() & MOD_MASK_CTRL) {
                    // Clear Ctrl modifier temporarily, send Up arrow, then restore
                    uint8_t mods = get_mods();
                    clear_mods();
                    tap_code(KC_UP);
                    set_mods(mods);
                } else {
                    // Otherwise send { (left brace)
                    tap_code16(KC_LCBR);
                }
            }
            return false;

        case CTRL_L:
            if (record->event.pressed) {
                if (get_mods() & MOD_MASK_CTRL) {
                    // Clear Ctrl modifier temporarily, send Right arrow, then restore
                    uint8_t mods = get_mods();
                    clear_mods();
                    tap_code(KC_RIGHT);
                    set_mods(mods);
                } else {
                    // Otherwise send } (right brace)
                    tap_code16(KC_RCBR);
                }
            }
            return false;

        default:
            return true;
    }
}

// ============================================================================
// Encoder Configuration (if present)
// ============================================================================
#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_BASE] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)}, [_LOWER] = {ENCODER_CCW_CW(KC_PGUP, KC_PGDN)}, [_RAISE] = {ENCODER_CCW_CW(KC_BRID, KC_BRIU)}, [_FUNCTION] = {ENCODER_CCW_CW(KC_MPRV, KC_MNXT)}, [_ADJUST] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
};
#endif
