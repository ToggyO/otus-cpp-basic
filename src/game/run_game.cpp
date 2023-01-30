#include <iostream>

#include "game.h"

// TODO: check include
#include "../libs/value_checker/value_checker.h"
#include "../libs/randomizer/randomizer.h"
#include "../libs/scores_manager/scores_manager.h"
//

const int easy = 10;
const int medium = 50;
const int hard = 100;

void printScoresTable(Scores::ScoresManager &manager);
int defineMaxValue(const gameSettings &settings);

int runGame(const gameSettings &settings)
{
    Scores::ScoresManager manager(settings.filePath);

    if (settings.showScoresOnly)
    {
        printScoresTable(manager);
        return 0;
    }

    int max_value = defineMaxValue(settings);
    int target_value = Randomizer::getRandomUnsignedInt(max_value);

    if (DEBUG)
    {
		std::cout << "max value " << max_value << std::endl;
	    std::cout << "target value " << target_value << std::endl;
    }

    std::string user_name;
    std::cout << "Hi! Enter your name, please:" << std::endl;
    std::getline(std::cin, user_name);

    if (manager.WriteScore(user_name, ValueChecker::checkValue(target_value)) < 0)
    {
        return -1;
    }

    printScoresTable(manager);
    
    return 0;
}

void printScoresTable(Scores::ScoresManager &manager)
{
    std::cout << "High scores table:" << std::endl;

    auto scores = manager.GetScoresList();
    if (scores.empty())
    {
        std::cout << "No data!" << std::endl;
        return;
    }    


    for (const auto &score : scores)
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