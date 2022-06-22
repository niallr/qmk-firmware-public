/*
Copyright 2021 Adam Honse

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
#include "version.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layer_names {
    _BASE, /* Normal QWERTY mapping */ 
    _FN, /* FN mapping */
	_FCAP, /* Caps Lock (hold) mapping */
	_FTAB, /* Caps Lock (hold) mapping */
};

enum my_keycodes {
  MY_LTGT, // <>
  MY_DPIP, // ||
  MY_DAMP, // &&
};

enum macro_id {
  M_EMAIL,
  M_RANDDIGIT,
  M_RANDLETTER,
  M_RANDDIGRN,
  M_ADSPAM,
};

#define EMAIL M(M_EMAIL) /* shortcut for email */
#define RANDDIG M(M_RANDDIGIT)
#define RANDALP M(M_RANDLETTER)
#define RANDDRN M(M_RANDDIGRN)
#define ADSPAM M(M_ADSPAM)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*  Row:        0           1           2           3         4           5        6        7           8           9           10          11          12          13       */
    [_BASE] = { {   KC_ESC,     KC_1,       KC_2,       KC_3,     KC_4,       KC_5,    KC_6,    KC_7,       KC_8,       KC_9,       KC_0,       KC_MINS,    KC_EQL,     KC_BSPC, },
                {   LT(_FTAB, KC_TAB),     KC_Q,       KC_W,       KC_E,     KC_R,       KC_T,    KC_Y,    KC_U,       KC_I,       KC_O,       KC_P,       KC_LBRC,    KC_RBRC,    KC_BSLS, },
                {   LT(_FCAP, KC_CAPS),    KC_A,       KC_S,       KC_D,     KC_F,       KC_G,    KC_H,    KC_J,       KC_K,       KC_L,       KC_SCLN,    KC_QUOT,    KC_NO,      KC_ENT,  },
                {   KC_LSPO,    KC_NO,      KC_Z,       KC_X,     KC_C,       KC_V,    KC_B,    KC_N,       KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,    KC_NO,      KC_RSPC, },
                {   KC_LCTL,    KC_LGUI,    KC_LALT,    KC_NO,    KC_NO,      KC_NO,   KC_SPC,  KC_NO,      KC_NO,      KC_RALT,    MO(_FN),    KC_APP,      KC_NO,     KC_RCTL, },
              },
    /*  Row:        0           1           2           3         4           5        6        7           8           9           10          11          12          13       */
    [_FN]   = { {   KC_GRV,     KC_F1,      KC_F2,      KC_F3,    KC_F4,      KC_F5,   KC_F6,   KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_F11,     KC_F12,     KC_DEL, },
                {   RESET,      _______,    KC_UP,      _______,  _______,    _______, _______, _______,    _______,    KC_INS,    KC_PSCR,    KC_SLCK,     KC_BRK,     KC_NUBS, },
                {   _______,    KC_LEFT,    KC_DOWN,    KC_RIGHT, KC_MPRV,    KC_MPLY, KC_MNXT, KC_VOLD,    KC_MUTE,    KC_VOLU,     KC_HOME,   KC_PGUP,    _______,    _______, },
                {   _______,    _______,    _______,    _______,  _______,    _______, _______, _______,    _______,    KC_MSTP,    KC_END,     KC_PGDN,    _______,    _______, },
                {   RANDDIG,    RANDALP,    EMAIL,      _______,  _______,    _______, _______, _______,    _______,    _______,    _______,    _______,    _______,    _______, },
             },
    /*  Row:        0           1           2           3         4           5        6        7           8           9           10          11          12          13       */
    [_FCAP]   = { {   KC_GRV,     KC_F1,      KC_F2,      KC_F3,    KC_F4,      KC_F5,   KC_F6,   KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_F11,     KC_F12,     KC_DEL, },
                {   _______,    _______,    KC_UP,      _______,  _______,    _______, _______, _______,    _______,    KC_INS,    KC_PSCR,    KC_SLCK,     KC_BRK,     KC_NUBS, },
                {   _______,    KC_LEFT,    KC_DOWN,    KC_RIGHT, KC_MPRV,    KC_MPLY, KC_MNXT, KC_VOLD,    KC_MUTE,    KC_VOLU,     KC_HOME,   KC_PGUP,    _______,    _______, },
                {   _______,    _______,    _______,    _______,  _______,    _______, _______, _______,    _______,    KC_MSTP,    KC_END,     KC_PGDN,    _______,    _______, },
                {   _______,     _______,   ADSPAM,     _______,  _______,    _______, _______, _______,    _______,    RANDDRN,    _______,    _______,    _______,    _______, },
             },
    /*  Row:        0           1           2           3         4           5        6        7           8           9           10          11          12          13       */
	[_FTAB]   = { {   KC_GRV,     KC_F1,      KC_F2,      KC_F3,    KC_F4,      KC_F5,   KC_F6,   KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_F11,     KC_F12,     KC_DEL, },
			{   _______,    KC_WH_U,    KC_MS_U,    KC_WH_D,  _______,    _______, _______, _______,    _______,    _______,    _______,    _______,    _______,    _______, },
			{   _______,    KC_MS_L,    KC_MS_D,    KC_MS_R,  _______,    _______, _______, KC_BTN1,    KC_BTN2,    KC_BTN3,    _______,    _______,    _______,    _______, },
			{   _______,    _______,    _______,    _______,  _______,    _______, _______, _______,    _______,    _______,    _______,    _______,    _______,    _______, },
			{   _______,    _______,    _______,    _______,  _______,    _______, _______, _______,    _______,    _______,    _______,    _______,    _______,    _______, },
             }
};

bool M_ADSPAM_track_bool;
uint32_t macro_timer;

/* generate random number between min and max */
uint16_t rval_in_range(uint16_t min, uint16_t max)
{
	srand(timer_read());
	return rand() % (max + 1 - min) + min;
}


const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  uint8_t rval;
  switch(id) {
  case M_ADSPAM:
    M_ADSPAM_track_bool = record->event.pressed; // change to "if (record->event.pressed) { M_ADSPAM_track_bool ^= 1; }" for toggle
    if (M_ADSPAM_track_bool) {
      macro_timer = timer_read();
	}
    break;
  case M_EMAIL:
    if (record->event.pressed) {
      SEND_STRING("email");
	  SEND_STRING(SS_LSFT("'"));
	  SEND_STRING("here.net");
    }
    break;
  case M_RANDDIGIT:
    /* Generate, based on random number generator, a keystroke for
       a numeric digit chosen at random */
    srand(timer_read());
    if (record->event.pressed) {
      rval = rand() % 10; 
      /* Note that KC_1 thru KC_0 are a contiguous range */
      register_code (KC_1 + rval);
      unregister_code (KC_1 + rval);
    }
    break;
  case M_RANDDIGRN:
    /* Generate, based on rval_in_range(min, max), a keystroke for
       a numeric digit chosen at random */
    if (record->event.pressed) {
      rval = rval_in_range(0, 9);
      /* Note that KC_1 thru KC_0 are a contiguous range */
      register_code (KC_1 + rval);
      unregister_code (KC_1 + rval);
    }
    break;
  case M_RANDLETTER:
    /* Generate, based on random number generator, a keystroke for
       a letter chosen at random */
    /* Here, we mix the LCRNG with low bits from one of the system
       clocks via XOR in the theory that this may be more random
       than either separately */
    srand(timer_read());
    if (record->event.pressed) {
      rval = rand() % 26;
      register_code (KC_A + rval);
      unregister_code (KC_A + rval);
    }
    break;

  }
  return MACRO_NONE;
};

void pause_nr(uint16_t i_wait) {
	uint16_t recording_timer;

	recording_timer = timer_read();

	while (timer_elapsed(recording_timer) < i_wait) {
		wait_ms(10);
	}
}

void press_key(uint16_t key) {
  register_code(key);
  unregister_code(key);
}

void press_two_keys(uint16_t key1, uint16_t key2) {
  register_code(key1);
  register_code(key2);
  unregister_code(key2);
  unregister_code(key1);
}

void press_three_keys(uint16_t key1, uint16_t key2, uint16_t key3) {
  register_code(key1);
  register_code(key2);
  register_code(key3);
  unregister_code(key3);
  unregister_code(key2);
  unregister_code(key1);
}

/*
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case M_ADSPAM:
      M_ADSPAM_track_bool = record->event.pressed;
      if (M_ADSPAM_track_bool) { macro_timer = timer_read(); }
      break;
	  
    case MY_LTGT: // <>
      if (record->event.pressed) {
        press_two_keys(KC_LSFT, KC_LABK);
        press_two_keys(KC_LSFT, KC_RABK);
      }

      return false;

    case MY_DPIP: // ||
      if (record->event.pressed) {
        press_two_keys(KC_LSFT, KC_PIPE);
        press_two_keys(KC_LSFT, KC_PIPE);
      }

      return false;

    case MY_DAMP: // &&
      if (record->event.pressed) {
        press_two_keys(KC_LSFT, KC_AMPR);
        press_two_keys(KC_LSFT, KC_AMPR);
      }

      return false;
  }

  return true;
}
*/

void matrix_scan_user(void) {
  if ( M_ADSPAM_track_bool && (timer_elapsed(macro_timer) > rval_in_range(10, 20)) ) {
	register_code(KC_A);
	pause_nr(rval_in_range(40, 60));
	unregister_code(KC_A);
	
	pause_nr(rval_in_range(10, 20));
	
	register_code(KC_D);
	pause_nr(rval_in_range(40, 60));
	unregister_code(KC_D);
    macro_timer = timer_read();
   }
}

void rgb_matrix_indicators_user(void) {
    switch (get_highest_layer(layer_state)) {
        case _FTAB:
            rgb_matrix_set_color_all(0,0,0);
			rgb_matrix_set_color(14, 255, 0, 0);
            break;
        case _FCAP:
            rgb_matrix_set_color_all(0,0,0);
			rgb_matrix_set_color(28, 255, 0, 0);
            break;
        default:
            break;
    }
}