#include "keymap_common.h"

const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* qwerty */
    KEYMAP(FN3,  FN7,  FN11, ESC,     Q,    W,    E,    R,    T,    Y,    U,    I,    O,    P, BSPC,  FN1,  FN0, WH_U, \
           FN4,  FN8,  FN12, TAB,     A,    S,    D,    F,    G,    H,    J,    K,    L, SCLN,  ENT,  FN2, RSFT, WH_D, \
           FN5,  FN9,  FN13, LSFT,    Z,    X,    C,    V,    B,    N,    M, COMM,  DOT, SLSH, RSFT, RCTL,   UP, RALT, \
           FN6, FN10,  FN14, SPC,  LCTL, LALT, LGUI,  FN2,  DEL,  SPC,  FN1, MINS,  EQL, LBRC, RBRC, LEFT, DOWN, RGHT),


    /* dvorak */
    KEYMAP(TRNS, TRNS, TRNS, ESC,  QUOT, COMM,  DOT,    P,    Y,    F,    G,    C,    R,    L, BSPC,  FN1,  FN0, TRNS, \
           TRNS, TRNS, TRNS, TAB,     A,    O,    E,    U,    I,    D,    H,    T,    N,    S,  ENT,  FN2, TRNS, TRNS, \
           TRNS, TRNS, TRNS, LSFT, SCLN,    Q,    J,    K,    X,    B,    M,    W,    V,    Z, RSFT, TRNS, TRNS, TRNS, \
           TRNS, TRNS, TRNS, SPC,  LCTL, LALT, LGUI,  FN2,  DEL,  SPC,  FN1, MINS,  EQL, LBRC, RBRC, TRNS, TRNS, TRNS),

    /* FN1 (up) */
    KEYMAP(TRNS, TRNS, TRNS, TRNS,    1,    2,    3,    4,    5,    6,    7,    8,    9,    0, TRNS, TRNS, TRNS, TRNS, \
           TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, LEFT, DOWN,   UP, RGHT, TRNS, TRNS, TRNS, TRNS, TRNS, \
           TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, \
           TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,  GRV, QUOT, BSLS, TRNS, TRNS, TRNS, TRNS),

    /* FN2 (down) */
    KEYMAP(TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,   F1,   F2,   F3,   F4,   F5,   F6, TRNS, TRNS, TRNS, TRNS, \
           TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,   F7,   F8,   F9,  F10,  F11,  F12, TRNS, TRNS, TRNS, TRNS, \
           TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,  INS, HOME,  END, PGUP, PGDN, PAUS, PSCR, MENU, TRNS, TRNS, TRNS, TRNS, \
           TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS),
};

enum macro_id {
    GUI_0,
    GUI_1,
    GUI_2,
    GUI_3,
    GUI_4,
    GUI_5,
    GUI_6,
    GUI_7,
    GUI_8,
    GUI_9,
    GUI_10,
    GUI_11,
};


const uint16_t PROGMEM fn_actions[] = {
    [0] = ACTION_LAYER_MOMENTARY(1), //dvorak
    [1] = ACTION_LAYER_MOMENTARY(2), //fn up
    [2] = ACTION_LAYER_MOMENTARY(3), //fn down
    [3] = ACTION_MACRO(GUI_0),
    [4] = ACTION_MACRO(GUI_1),
    [5] = ACTION_MACRO(GUI_2),
    [6] = ACTION_MACRO(GUI_3),
    [7] = ACTION_MACRO(GUI_4),
    [8] = ACTION_MACRO(GUI_5),
    [9] = ACTION_MACRO(GUI_6),
    [10] = ACTION_MACRO(GUI_7),
    [11] = ACTION_MACRO(GUI_8),
    [12] = ACTION_MACRO(GUI_9),
    [13] = ACTION_MACRO(GUI_10),
    [14] = ACTION_MACRO(GUI_11),
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    switch (id) {
         case GUI_0:
            return (record->event.pressed ?
                MACRO( D(RGUI), D(Q), W(255), U(RGUI), U(Q), END ) :
                MACRO( D(RGUI), D(W), W(255), U(RGUI), U(W), END ));
        case GUI_1:
            return (record->event.pressed ?
                MACRO( D(RGUI), D(E), W(255), U(RGUI), U(E), END ) :
                MACRO( D(RGUI), D(R), W(255), U(RGUI), U(R), END ));
        case GUI_2:
            return (record->event.pressed ?
                MACRO( D(RGUI), D(T), W(255), U(RGUI), U(T), END ) :
                MACRO( D(RGUI), D(Y), W(255), U(RGUI), U(Y), END ));
        case GUI_3:
            return (record->event.pressed ?
                MACRO( D(RGUI), D(U), W(255), U(RGUI), U(U), END ) :
                MACRO( D(RGUI), D(I), W(255), U(RGUI), U(I), END ));
        case GUI_4:
            return (record->event.pressed ?
                MACRO( D(RGUI), D(O), W(255), U(RGUI), U(O), END ) :
                MACRO( D(RGUI), D(P), W(255), U(RGUI), U(P), END ));
        case GUI_5:
            return (record->event.pressed ?
                MACRO( D(RGUI), D(A), W(255), U(RGUI), U(A), END ) :
                MACRO( D(RGUI), D(S), W(255), U(RGUI), U(S), END ));
        case GUI_6:
            return (record->event.pressed ?
                MACRO( D(RGUI), D(D), W(255), U(RGUI), U(D), END ) :
                MACRO( D(RGUI), D(F), W(255), U(RGUI), U(F), END ));
        case GUI_7:
            return (record->event.pressed ?
                MACRO( D(RGUI), D(G), W(255), U(RGUI), U(G), END ) :
                MACRO( D(RGUI), D(H), W(255), U(RGUI), U(H), END ));
        case GUI_8:
            return (record->event.pressed ?
                MACRO( D(RGUI), D(J), W(255), U(RGUI), U(J), END ) :
                MACRO( D(RGUI), D(K), W(255), U(RGUI), U(K), END ));
        case GUI_9:
            return (record->event.pressed ?
                MACRO( D(RGUI), D(L), W(255), U(RGUI), U(L), END ) :
                MACRO( D(RGUI), D(Z), W(255), U(RGUI), U(Z), END ));
        case GUI_10:
            return (record->event.pressed ?
                MACRO( D(RGUI), D(X), W(255), U(RGUI), U(X), END ) :
                MACRO( D(RGUI), D(C), W(255), U(RGUI), U(C), END ));
        case GUI_11:
            return (record->event.pressed ?
                MACRO( D(RGUI), D(V), W(255), U(RGUI), U(V), END ) :
                MACRO( D(RGUI), D(B), W(255), U(RGUI), U(B), END ));
    }
    return MACRO_NONE;
}
