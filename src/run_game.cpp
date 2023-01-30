#include <experimental/filesystem>
#include <iostream>

#include "config.h"
#include "game.h"

// TODO: check include
#include "libs/value_checker/value_checker.h"
#include "libs/randomizer/randomizer.h"
#include "libs/scores_manager/scores_manager.h"
//

const int easy = 10;
const int medium = 50;
const int hard = 100;

void printScoresTable(Scores::ScoresManager &manager);
int defineMaxValue(const gameSettings &settings);

int runGame(const gameSettings &settings)
{
    auto file_path = std::experimental::filesystem::path(PROJECT_ROOT)
                .append("src")
                .append("scores.txt");

    Scores::ScoresManager manager(file_path);

    if (settings.showScoresOnly)
    {
        printScoresTable(manager);
        return 0;
    }

    int max_value = defineMaxValue(settings);
    int target_value = getRandomUnsignedInt(max_value);

    if (DEBUG)
    {
		std::cout << "max value " << max_value << std::endl;
	    std::cout << "target value " << target_value << std::endl;
    }

    std::string user_name;
    std::cout << "Hi! Enter your name, please:" << std::endl;
    std::cin >> user_name;
    if (std::cin.fail())
    {
        std::cerr << "Wrong input data!" << std::endl;
        return -1;
    }

    if (manager.WriteScore(user_name, checkValue(target_value)) < 0)
    {
        return -1;
    }

    printScoresTable(manager);
    
    return 0;
}

void printScoresTable(Scores::ScoresManager &manager)
{
    std::cout << "High scores table:" << std::endl;
    for (const auto &score : manager.GetScoresList())
    {
        std::cout << score << std::endl;
    }
}

int defineMaxValue(const gameSettings &settings)
{
    if (settings.levelIsDefined)
    {
        switch (settings.level)
        {
        case DifficultyLevel::EASY:
            return easy;
        
        case DifficultyLevel::HIGH:
            return hard;

        default:
            return medium;
        }
    }

    return settings.maxValue;
}