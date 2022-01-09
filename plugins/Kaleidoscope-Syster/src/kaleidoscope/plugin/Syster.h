/* -*- mode: c++ -*-
 * Kaleidoscope-Syster -- Symbolic input system
 * Copyright (C) 2017-2021  Keyboard.io, Inc
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
#include <Kaleidoscope-Ranges.h>

#define SYSTER_MAX_SYMBOL_LENGTH 32

#define SYSTER Key(kaleidoscope::ranges::SYSTER)

namespace kaleidoscope {
namespace plugin {

class Syster : public kaleidoscope::Plugin {
 public:
  typedef enum {
    StartAction,
    EndAction,
    SymbolAction
  } action_t;

  Syster() {}

  static void reset();

  bool is_active();

  EventHandlerResult onNameQuery();
  EventHandlerResult onKeyEvent(KeyEvent &event);

 private:
  static char symbol_[SYSTER_MAX_SYMBOL_LENGTH + 1];
  static uint8_t symbol_pos_;
  static bool is_active_;
};

} // namespace plugin

void eraseChars(int8_t n);

} // namespace kaleidoscope

const char keyToChar(Key key);

void systerAction(kaleidoscope::plugin::Syster::action_t action, const char *symbol);

extern kaleidoscope::plugin::Syster Syster;
