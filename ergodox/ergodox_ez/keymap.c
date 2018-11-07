#include QMK_KEYBOARD_H
#include "debug.h"
#include "keymap_swedish.h"
#include "action_layer.h"
#include "version.h"

// Make it easier to read the layouts
#define _______ KC_TRNS

// Layers 
#define RAISE TO(_RAISE)
#define LOWER TO(_LOWER)
#define SWEDISH TG(_SWEDISH)

// Combo keys
#define ESC_L1  LT(RAISE, KC_ESC)
#define TAB_L2  LT(LOWER, KC_TAB)

#define _QWERTY 0
#define _SWEDISH 1
#define _LOWER 2
#define _RAISE 3
#define _SUPERDUPER 4

// Combo : SuperDuper layer from S+D (R+S in Colemak)
#define SUPERDUPER_COMBO_COUNT 1
#define EECONFIG_SUPERDUPER_INDEX (uint8_t *) 19

#define SWEA  0x00E5 // swedish a
#define CSWEA  0x00C5 // Capital swedish aa
#define SWEAA 0x00E4
#define CSWEAA  0x00C4 // Capital swedish aa
#define SWEO  0x00F6
#define CSWEO  0x00D6 // Capital swedish o

// Macro Declarations
enum {
    _SWEO = 0,
    _SWEA,
    _SWEAA,
    SHRUG,
    FLIP
    // ..., the rest of your macros
};

enum process_combo_event {
  CB_SUPERDUPER,
};

const uint16_t PROGMEM superduper_combos[SUPERDUPER_COMBO_COUNT][3] = {
  [_QWERTY] = {KC_S, KC_D, COMBO_END},
};

combo_t key_combos[COMBO_COUNT] = {
  [CB_SUPERDUPER] = COMBO_ACTION(superduper_combos[_QWERTY]),
};


const uint16_t empty_combo[] = {COMBO_END};

void set_superduper_key_combos(void);
void clear_superduper_key_combos(void);

// Macro Definitions
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  switch(id) {
    case _SWEA: {
        if (record->event.pressed) {
	    if (keyboard_report->mods & (MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT))) {
		unicode_input_start();
      		register_hex(CSWEA);
      		unicode_input_finish();
	    } else { 
		unicode_input_start();
      		register_hex(SWEA);
      		unicode_input_finish();
            }
        }
	
        return false;
    }

    case _SWEAA: {
        if (record->event.pressed) {
	    if (keyboard_report->mods & (MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT))) {
		unicode_input_start();
      		register_hex(CSWEAA);
      		unicode_input_finish();
	    } else { 
		unicode_input_start();
      		register_hex(SWEAA);
      		unicode_input_finish();
            }
        }
	
        return false;
    }

    case _SWEO: {
        if (record->event.pressed) {
	    if (keyboard_report->mods & (MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT))) {
		unicode_input_start();
      		register_hex(CSWEO);
      		unicode_input_finish();
	    } else { 
		unicode_input_start();
      		register_hex(SWEO);
      		unicode_input_finish();
            }
        }
	
        return false;
    }

    case SHRUG: {
        if (record->event.pressed) {
		// ¯\_(ツ)_/¯
		unicode_input_start();
		register_hex(0x00AF);
		unicode_input_finish();

		unicode_input_start();
		register_hex(0x005C);
		unicode_input_finish();

		unicode_input_start();
		register_hex(0x005F);
		unicode_input_finish();

		unicode_input_start();
		register_hex(0x0028);
		unicode_input_finish();

		unicode_input_start();
		register_hex(0x30C4);
		unicode_input_finish();

		unicode_input_start();
		register_hex(0x0029);
      		unicode_input_finish();
		
		unicode_input_start();
		register_hex(0x005F);
      		unicode_input_finish();
		
		unicode_input_start();
		register_hex(0x002F);
      		unicode_input_finish();

		unicode_input_start();
		register_hex(0x00AF);
      		unicode_input_finish();
        }
	
        return false;
    }

    case FLIP: {
	// (╯°□°）╯︵ ┻━┻
       if (record->event.pressed) {
	//       0028 256F 00B0 25A1 00B0 FF09 256F FE35 0020 253B 2501 253B
		unicode_input_start();
      		register_hex(0x0028);
      		unicode_input_finish();
		
		unicode_input_start();
      		register_hex(0x256F);
      		unicode_input_finish();
		
		unicode_input_start();
      		register_hex(0x00B0);
      		unicode_input_finish();
		
		unicode_input_start();
      		register_hex(0x25A1);
      		unicode_input_finish();
		
		unicode_input_start();
      		register_hex(0x00B0);
      		unicode_input_finish();
		
		unicode_input_start();
      		register_hex(0xFF09);
      		unicode_input_finish();
		
		unicode_input_start();
      		register_hex(0x256F);
      		unicode_input_finish();
		
		unicode_input_start();
      		register_hex(0xFE35);
      		unicode_input_finish();
		
		unicode_input_start();
      		register_hex(0x0020);
      		unicode_input_finish();
		
		unicode_input_start();
      		register_hex(0x253B);
      		unicode_input_finish();
		
		unicode_input_start();
      		register_hex(0x2501);
      		unicode_input_finish();

		unicode_input_start();
      		register_hex(0x253B);
      		unicode_input_finish();
        }
	
        return false;
    }

  }

  return MACRO_NONE;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |Swedish |   1  |   2  |   3  |   4  |   5  |      |           |      |   6  |   7  |   8  |   9  |   0  |   =    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |Tab/L2  |   Q  |   W  |   E  |   R  |   T  |      |           |      |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |Esc/L1  |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |   '    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |Shift   |Z/Ctrl|X/Alt |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |./Alt |/Ctrl | -/Shift|
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | Left |      |      | Lead | Right|                                       | Up   | Shrug| Flip |      | Down |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |Print |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      | Home |       | PgUp |      |      |
 *                                 | Space| Bksp |------|       |------| Tab  |Enter |
 *                                 |      |      | End  |       |PgDown|      |      |
 *                                 `--------------------'       `--------------------'
 */
[_QWERTY] = LAYOUT_ergodox(
        // left hand
        SWEDISH,  KC_1,        KC_2,        KC_3,    KC_4,     KC_5, _______,
        TAB_L2,   KC_Q,        KC_W,        KC_E,    KC_R,     KC_T, _______,
        ESC_L1,   KC_A,        KC_S,        KC_D,    KC_F,     KC_G,
        KC_LSFT,  CTL_T(KC_Z), ALT_T(KC_X), KC_C,    KC_V,     KC_B, _______,
        KC_LEFT,  _______,     _______,     KC_LGUI, KC_RIGHT,

                                                                     _______, _______,
                                                                              KC_HOME,
                                                          KC_SPC,    KC_BSPC, KC_END,

        // right hand
        _______,   KC_6,     KC_7,    KC_8,    KC_9,          KC_0,           KC_PEQL,
        _______,   KC_Y,     KC_U,    KC_I,    KC_O,          KC_P,           KC_BSLASH,
                   KC_H,     KC_J,    KC_K,    KC_L,    	     KC_SCLN,        KC_QUOT,
        _______,   KC_N,     KC_M,    KC_COMM, ALT_T(KC_DOT), CTL_T(KC_SLSH), SFT_T(KC_MINS),
        KC_UP,     M(SHRUG), M(FLIP), _______, KC_DOWN,

        _______, KC_PSCREEN,
        KC_PGDN,
        KC_PGUP, KC_TAB,  KC_ENT
    ),

/* Keymap 2: Swedish layer 
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      | å      |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |      |      |      | ö    | ä      |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */

[_SWEDISH] = LAYOUT_ergodox(
    // left hand
    _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______,

                                                       _______, _______,
                                                                _______,
                                              _______, _______, _______,
    // right hand
    _______, _______, _______, _______, _______, _______,  _______,
    _______, _______, _______, _______, _______, _______,  M(_SWEA),
             _______, _______, _______, _______, M(_SWEO), M(_SWEAA),
    _______, _______, _______, _______, _______, _______,  _______,
                      _______, _______, _______, _______,  _______,

    _______, _______,
    _______,
    _______, _______, _______
),

/* Keymap 1: Raise (symbols)
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  F1    | F2   | F3   | F4   | F5   |  F6  |      |           |      | F7   | F8   | F9   | F10  | F11  | F12    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   !  |   @  |  {   |   }  |   |  |      |           |      |  &   |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   #  |   $  |   (  |   )  |  `   |------|           |------|  +   |  -   |  *   |  /   |  =   |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   %  |   ^  |   [  |   ]  |  ~   |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      | Del  |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[_RAISE] = LAYOUT_ergodox(
       // left hand
       KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,    _______,
       _______, KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_PIPE,  _______,
       _______, KC_HASH, KC_DLR,  KC_LSPO, KC_RSPC, KC_GRAVE,
       _______, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD,  _______,
       _______, _______, _______, _______, _______,

                                                                     _______, _______,
                                                                              _______,
                                                            _______, KC_DEL,  _______,
       // right hand
       _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,   KC_F12,
       _______, KC_AMPR, _______, _______, _______, _______,  _______,
                KC_PLUS, KC_MINS, KC_ASTR, KC_SLSH, KC_EQUAL, _______,
       _______, _______, _______, _______, _______, _______,  _______,
                _______, _______, _______, _______, _______,

       _______, _______,
       _______,
       _______, _______, _______
),
/* Keymap 2: Lower (numpad and Fn keys)
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |  F1  |  F2  |  F3  |  F4  | F5   |      |           |      |      |  7   |  8   |  9   |  -   |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |  Alt |  F6  |  F7  |  F8  | F9   |------|           |------|      |  4   |  5   |  6   |  +   |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        | Ctrl |  F10 | F11  |  F12 |      |      |           |      |      |  1   |  2   |  3   | Enter|        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |  0   |  ,   |  .   |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[_LOWER] = LAYOUT_ergodox(
       // left hand
       _______, _______, _______, _______, _______, _______, _______,
       KC_TILD, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______,
       _______, KC_LALT, KC_F6,   KC_F7,   KC_F8,   KC_F9,
       _______, KC_LCTL, KC_F10,  KC_F11,  KC_F11,  KC_F12,  _______,
       _______, _______, _______, _______, _______,

                                                                       _______, _______,
                                                                                _______,
                                                              _______, _______, _______,

       // right hand
       _______,  _______, _______, _______, _______, _______, _______,
       _______,  _______, KC_7,    KC_8,    KC_9,    KC_PMNS, _______,
                 _______, KC_4,    KC_5,    KC_6,    KC_PPLS, _______,
       _______,  _______, KC_1,    KC_2,    KC_3,    KC_ENT,  _______,
                          KC_0,    KC_COMM, KC_DOT,  _______, _______,

       _______, _______,
       _______,
       _______, _______, _______
),
/* Keymap 3: Super Duper layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      | PgUp | Prev | Next | Vol- |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        | Alt  |[Super Duper]| Cmd  |      |------|           |------| Left | Down |  Up  | Right| Play |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      | PgDwn|      | Mute | Vol+ |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 | Shift|      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[_SUPERDUPER] = LAYOUT_ergodox(
    // left hand
    _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,
    _______, KC_LALT, _______, _______, KC_LGUI, _______,
    _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______,

                                                       _______, _______,
                                                                _______,
                                              KC_LSFT, _______, _______,
    // right hand
    _______, _______, _______, _______, _______, _______, _______,
    _______, _______, KC_PGUP, KC_MPRV, KC_MNXT, KC_VOLU, _______,
             KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_MPLY, KC_MNXT,
    _______, _______, KC_PGDN, _______, KC_MUTE, KC_VOLD, _______,
                      _______, _______, _______, _______, _______,

    _______, _______,
    _______,
    _______, _______, _______
),
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
    set_unicode_input_mode(UC_LNX);
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {
    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    
    switch (layer) {
	case _QWERTY:
            // *--
            ergodox_right_led_1_on();
	    break;
	case _SWEDISH:
            // -*-
            ergodox_right_led_2_on();
            break;
        case _RAISE:
            // **-
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            break;

        case _LOWER:
            // --*
            ergodox_right_led_3_on();
            break;
        case _SUPERDUPER:
            // *-*
            ergodox_right_led_1_on();
            ergodox_right_led_3_on();
            break;
        default:
            // none
            break;
    }
};

//
/* Keymap N: Empty template
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */

void set_superduper_key_combos(void) {
  uint8_t layer = eeprom_read_byte(EECONFIG_SUPERDUPER_INDEX);

  switch (layer) {
    case _QWERTY:
      key_combos[CB_SUPERDUPER].keys = superduper_combos[layer];
      break;
  }
}

void clear_superduper_key_combos(void) {
  key_combos[CB_SUPERDUPER].keys = empty_combo;
}

void process_combo_event(uint8_t combo_index, bool pressed) {
  if (pressed) {
    switch(combo_index) {
      case CB_SUPERDUPER:
        layer_on(_SUPERDUPER);
        break;
    }
  } else {
    layer_off(_SUPERDUPER);
    unregister_mods(MOD_BIT(KC_LGUI) | MOD_BIT(KC_LCTL) | MOD_BIT(KC_LALT)); // Sometimes mods are held, unregister them
  }
}
