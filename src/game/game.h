#pragma once

#include "../main.h"
#include "../debugger.h"
#include "../game_settings/game_settings.hpp"

int runGame(const GameSettings &settings, const IDebugger *debugger = nullptr);


