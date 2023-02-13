#pragma once

#include <map>
#include <string>

#include "../main.h"
#include "option.hpp"
#include "option_type.hpp"

struct GameSettings
{
    std::string filePath;
    int maxValue;
    bool showScoresOnly;
    bool levelIsDefined;
    DifficultyLevel level;

    GameSettings() : maxValue(100), showScoresOnly(false), levelIsDefined(false), level(DifficultyLevel::MEDIUM)
    {
        options[max_value_option] = Option{OptionType::Max, max_value_option, true};
        options[table_option] = Option{OptionType::Table, table_option, false};
        options[level_option] = Option{OptionType::Table, level_option, true};
    }

    int parseFromCmd(int argc, char* argv[]);
    void setFilePath(const std::string &filePath);

private:
    const std::string option_prefix = "-";
    const char* max_value_option = "max";
    const char* table_option = "table";
    const char* level_option = "level";
    std::map<std::string, Option> options;


    int applySetting(const std::string &option, const std::string &arg = "");
};
