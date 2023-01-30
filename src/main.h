#pragma once

extern bool DEBUG;

enum DifficultyLevel
{
    EASY = 1,
    MEDIUM,
    HIGH,
};

struct gameSettings
{
    std::string filePath;
    int maxValue;
    bool showScoresOnly;
    bool levelIsDefined;
    DifficultyLevel level;

    gameSettings() : maxValue(100), showScoresOnly(false), levelIsDefined(false), level(DifficultyLevel::MEDIUM)
    {}
};