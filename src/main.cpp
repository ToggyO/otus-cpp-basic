#include <iostream>
#include <cstring>

#include "game.h"

bool DEBUG = false;

int main(int argc, char* argv[])
{
    gameSettings settings;

    GameOptionsParser parser(settings);
    parser.Parse(argc, argv);

    return runGame(settings);
}