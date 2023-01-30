#pragma once

#include <string>

#include "../main.h"

class GameOptionsParser
{
public:
    GameOptionsParser(gameSettings &settings);
    int Parse(int argc, char* argv[]);

private:
    const char* option_prefix = "--";
    const char* max_value_option = "max";
    const char* table_option = "table";
    const char* level_option = "level";
    const char* debug_option = "debug";

    gameSettings &mSettings;

    int applySetting(const std::string &option, const std::string &arg = "");
};