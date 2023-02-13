#pragma once

#include <string>

#include "../main.h"

struct GameSettings
{
    std::string filePath;
    int maxValue;
    bool showScoresOnly;
    bool levelIsDefined;
    DifficultyLevel level;

    GameSettings() : maxValue(100), showScoresOnly(false), levelIsDefined(false), level(DifficultyLevel::MEDIUM)
    {}

    int parseFromCmd(int argc, char* argv[]);
    void setFilePath(const std::string &filePath);

private:
    const std::string option_prefix = "--";
    const char* max_value_option = "max";
    const char* table_option = "table";
    const char* level_option = "level";
    const char* debug_option = "debug";

    int applySetting(const std::string &option, const std::string &arg = "");
};