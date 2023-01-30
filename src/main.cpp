#include <experimental/filesystem>
#include <iostream>
#include <cstring>

#include "main.h"
#include "config.h"
#include "game/game.h"
#include "parser/game_options_parser.h"

bool DEBUG = false;

int main(int argc, char* argv[])
{
    gameSettings settings;

    settings.filePath = std::experimental::filesystem::path(getProjectRoot())
                .append("src")
                .append("scores.txt");

    GameOptionsParser parser(settings);
    parser.Parse(argc, argv);

    return runGame(settings);
}