/* -*- mode: c++ -*-
 * Kaleidoscope-Chords -- Chords
 * Copyright (C) 2017, 2018, 2019  Keyboard.io, Inc
 *
 * This program is free software: you can redistribute it and/or modify it under
 * the terms of the GNU General Public License as published by the Free Software
 * Foundation, version 3.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE. See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program. If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "kaleidoscope/Runtime.h"

namespace kaleidoscope {
namespace plugin {
class Chords : public kaleidoscope::Plugin {
 public:

  Chords(void) {}

  EventHandlerResult onSetup();
  EventHandlerResult onFocusEvent(const char *command);
  EventHandlerResult onKeyswitchEvent(Key &, KeyAddr, uint8_t);

  typedef struct {
    uint8_t length;
    Key keys[5];
    Key action;
    // Internal state
    uint8_t state;
    uint8_t pressed;
    uint32_t last_time;
  } Chord;

  /*static void setup(uint8_t max);

  static void max_layers(uint8_t max);

  static uint16_t keymap_base(void);

  static Key getKey(uint8_t layer, KeyAddr key_addr);
  static Key getKeyExtended(uint8_t layer, KeyAddr key_addr);

  static void updateKey(uint16_t base_pos, Key key);*/

 private:
  enum STATES {
    INACTIVE,   // No keys pressed
    PARTIAL,    // One but not all keys pressed
    PRESSED,    // All keys pressed, chord is pressed
    RELEASED,   // All keys were pressed, being released
    ABORTED     // Some keys were pressed, timed out, being released
  };

  /*static uint16_t keymap_base_;
  static uint8_t max_layers_;
  static uint8_t progmem_layers_;

  static Key parseKey(void);
  static void printKey(Key key);
  static void dumpKeymap(uint8_t layers, Key(*getkey)(uint8_t, KeyAddr));*/
};
}
}

extern kaleidoscope::plugin::Chords Chords;