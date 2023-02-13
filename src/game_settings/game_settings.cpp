#include <iostream>
#include <string>
#include <cstring>

#include "game_settings.hpp"

const char* cant_apply_settings = "Can't apply settings";

bool startsWith(const std::string& s, const std::string& prefix);

int GameSettings::parseFromCmd(int argc, char* argv[])
{
    std::string previous_option_name;
    std::string current_option_name;
    bool previous_arg_is_option = false;

    for (int i = 1; i < argc; i++)
    {
        auto arg = std::string{argv[i]};

        if (startsWith(arg, option_prefix))
        {
            current_option_name = arg.substr(option_prefix.size());

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

// TODO: remove
// int GameSettings::parseFromCmd(int argc, char* argv[])
// {
//     std::string previous_option_name;
//     std::string current_option_name;
//     bool previous_arg_is_option = false;

//     for (int i = 1; i < argc; i++)
//     {
//         auto arg = std::string{argv[i]};

//         if (startsWith(arg, option_prefix))
//         {
//             current_option_name = arg.substr(option_prefix.size());

//             if (i == (argc - 1))
//             {
//                 int exitCode = applySetting(current_option_name);
//                 if (exitCode < 0)
//                 {
//                     std::cerr << cant_apply_settings << std::endl;
//                     return exitCode;
//                 }
//             }

//             if (previous_arg_is_option)
//             {
//                 int exitCode = applySetting(previous_option_name);
//                 if (exitCode < 0)
//                 {
//                     std::cerr << cant_apply_settings << std::endl;
//                     return exitCode;
//                 }
//             }

//             previous_option_name = current_option_name;
//             previous_arg_is_option = true;
//             continue;
//         }
       
//         previous_arg_is_option = false;
//         int exitCode = applySetting(current_option_name, arg);
//         if (exitCode < 0)
//         {
//             std::cerr << cant_apply_settings << std::endl;
//             return exitCode;
//         }
//     }

//     return 0;
// }

int GameSettings::applySetting(const std::string &option, const std::string &arg)
{
    try
    {
        if (option == max_value_option)
        {
            maxValue = std::stoi(arg);
        }

        if (option == table_option)
        {
            showScoresOnly = true;
        }

        if (option == level_option)
        {
            // Вопрос: как лучше скастовать int в enum, чтобы словить ошибку, если в enum нет подходящего значения?
            int num = std::stoi(arg);
            levelIsDefined = true;
            level = static_cast<DifficultyLevel>(num);
        }
    }
    catch(const std::exception& e)
    {
        return -1;
    }

    return 0;
}

void GameSettings::setFilePath(const std::string &path)
{
    if (path.size() > 0)
    {
        filePath = path;
    }
}

bool startsWith(const std::string& s, const std::string& prefix) {
    return s.size() >= prefix.size() &&
           std::equal(prefix.begin(), prefix.end(), s.begin());
}