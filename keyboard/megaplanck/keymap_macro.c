#include "keymap_common.h"

const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*0: qwerty*/
    KEYMAP(ESC,    1,   2,   3,   4,   5,   6,   7,   8,   9,   0,MINS, EQL,BSPC,         \
           FN3,    Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,LBRC,RBRC,BSLS,         \
           FN0,    A,   S,   D,   F,   G,   H,   J,   K,   L,SCLN,QUOT, ENT,              \
           LSFT,   Z,   X,   C,   V,   B,   N,   M,COMM, DOT,SLSH,RSFT,                   \
           LCTL, FN1,LALT,           SPC,          RALT,LGUI, FN2,RCTL),

    /*1: dvorak*/
    KEYMAP(ESC,    1,   2,   3,   4,   5,   6,   7,   8,   9,   0,LBRC,RBRC,BSPC,         \
           TAB, QUOT,COMM, DOT,   P,   Y,   F,   G,   C,   R,   L,SLSH, EQL,BSLS,         \
           FN0,    A,   O,   E,   U,   I,   D,   H,   T,   N,   S,MINS, ENT,              \
           LSFT,SCLN,   Q,   J,   K,   X,   B,   M,   W,   V,   Z,RSFT,                   \
           LCTL, FN1,LALT,           SPC,          RALT,RGUI, FN2,RCTL),

    /*2: FN1 */
    KEYMAP(TRNS,TRNS,TRNS,NLCK,  P7,  P8,  P9,PMNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,        \
           TRNS,TRNS,  UP,TRNS,  P4,  P5,  P6,PSLS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,        \
           TRNS,LEFT,DOWN,RGHT,  P1,  P2,  P3,PPLS,TRNS,TRNS,TRNS,TRNS,TRNS,             \
           TRNS,TRNS,TRNS,TRNS,  P0,  P0,PDOT,PENT,TRNS,TRNS,TRNS,TRNS,                  \
           TRNS,TRNS,TRNS,          TRNS,          TRNS,TRNS,TRNS,TRNS),

    /*3: FN2, fn layer with special keys*/
    KEYMAP(GRV,   F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9, F10, F11, F12, DEL,        \
           TRNS,BTN1,MS_U,BTN2,BTN3,WH_U,TRNS,TRNS, INS,TRNS,PSCR,SLCK,PAUS,TRNS,        \
           TRNS,MS_L,MS_D,MS_R,WH_L,WH_D,WH_R,TRNS,TRNS,TRNS,HOME,PGUP,TRNS,             \
           TRNS,MUTE,VOLD,VOLU,TRNS,TRNS,TRNS,TRNS,TRNS, END,PGDN,TRNS,                  \
           TRNS,TRNS,TRNS,          TRNS,          TRNS,CAPS,TRNS,TRNS),
};

enum macro_id {
    ALT_TAB,
};

const uint16_t PROGMEM fn_actions[] = {
    [0] = ACTION_LAYER_MOMENTARY(2),
    [1] = ACTION_LAYER_TOGGLE(1), //switch dvorak <-> qwerty
    [2] = ACTION_LAYER_MOMENTARY(3),
    [3] = ACTION_MACRO(ALT_TAB),
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    switch (id) {
        case ALT_TAB:
	    return (record->event.pressed ?
                MACRO( D(RGUI), D(Q), W(255), U(RGUI), U(Q), END ) :
		MACRO( D(RGUI), D(W), W(255), U(RGUI), U(W), END ));
    }
    return MACRO_NONE;
}
