#include <experimental/filesystem>

#include "main.h"
#include "config.h"
#include "game/game.h"
#include "game_settings/game_settings.hpp"
#include "debugger/debugger.hpp"

int main(int argc, char* argv[])
{
    GameSettings settings;

    int parsseResult = settings.parseFromCmd(argc, argv);
    if (parsseResult < 0)
    {
        return parsseResult;
    }

    settings.setFilePath(
        std::experimental::filesystem::path(getProjectRoot())
            .append("src")
            .append("scores.txt"));

    Debugger *debugAgent = nullptr;

    #ifdef DEBUG_BUILD
    {
        Debugger debugger;
        debugAgent = &debugger;
    }
    #endif

    return runGame(settings, debugAgent);
}