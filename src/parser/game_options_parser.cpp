#include <cstring>
#include <iostream>
#include <string>

#include "game_options_parser.h"

const char* cant_apply_settings = "Can't apply settings";

GameOptionsParser::GameOptionsParser(gameSettings &settings) : mSettings(settings)
{}

int GameOptionsParser::Parse(int argc, char* argv[])
{
    std::string previous_option_name;
    std::string current_option_name;
    bool previous_arg_is_option = false;

    for (int i = 1; i < argc; i++)
    {
        auto arg = std::string{argv[i]};

        if ((int)arg.find(option_prefix) == 0)
        {
            current_option_name = arg.substr(std::strlen(option_prefix));

            if (i == (argc - 1))
            {
                int exitCode = applySetting(current_option_name);
                if (exitCode < 0)
                {
                    std::cerr << cant_apply_settings << std::endl;
                    return exitCode;
                }
            }

            if (previous_arg_is_option)
            {
                int exitCode = applySetting(previous_option_name);
                if (exitCode < 0)
                {
                    std::cerr << cant_apply_settings << std::endl;
                    return exitCode;
                }
            }

            previous_option_name = current_option_name;
            previous_arg_is_option = true;
            continue;
        }
       
        previous_arg_is_option = false;
        int exitCode = applySetting(current_option_name, arg);
        if (exitCode < 0)
        {
            std::cerr << cant_apply_settings << std::endl;
            return exitCode;
        }
    }

    return 0;
}

int GameOptionsParser::applySetting(const std::string &option, const std::string &arg)
{
    try
    {
        if (option == debug_option)
        {
            DEBUG = true;
        }

        if (option == max_value_option)
        {
            mSettings.maxValue = std::stoi(arg);
        }

        if (option == table_option)
        {
            mSettings.showScoresOnly = true;
        }

        if (option == level_option)
        {
            // Вопрос: как лучше скастовать int в enum, чтобы словить ошибку, если в enum нет подходящего значения?
            int num = std::stoi(arg);
            mSettings.levelIsDefined = true;
            mSettings.level = static_cast<DifficultyLevel>(num);
        }
    }
    catch(const std::exception& e)
    {
        return -1;
    }

    return 0;
}