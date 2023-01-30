#include <experimental/filesystem>
#include <list>
#include <iostream>
#include <algorithm>

#include "scores_manager.h"

const char* err_forbidden_char = "Username must not contain an invalid character";
const char* err_duplicate_username = "Username already exists. Please, tray another one";
const char* err_write_to_file = "Failed to write into file";
const char* err_read_from_file = "Failed to read from file";
const char Scores::ScoresManager::delimiter = '|';

std::list<Scores::Score> getScoresList(std::string file_path, char delimiter);

Scores::ScoresManager::ScoresManager(std::string file_path)
{
    if (file_path.size() == 0)
    {
        throw std::runtime_error("file mPath is required\n");
    }

    mPath = file_path;
    bool exists = std::experimental::filesystem::exists(mPath);
    if (!exists)
    {
        std::ofstream created(mPath);
        created.close();
    }
}

int Scores::ScoresManager::WriteScore(std::string user_name, ushort attempts_count)
{
    // Вопрос: кажется, что открытия файлового потока - затратная по времени и ресурсам операция.
    // Стоит ли кэшировать открытый поток в полях класса и переисользовать его? А закрывать в деструкторе.
    std::ofstream out_stream{mPath, std::ios_base::app};
    if (!out_stream.is_open())
    {
        throw std::runtime_error(err_write_to_file);
    }

    int delimiterPosition = user_name.find(delimiter, 0);
    if (delimiterPosition >= 0)
    {
        std::cout << err_forbidden_char << ' ' << '`' << delimiter << '`' << std::endl;
        return -1;
    }

    out_stream << user_name << delimiter;
    out_stream << attempts_count << std::endl;

    out_stream.close();
    return 0;
}

std::list<std::string> Scores::ScoresManager::GetScoresList(bool isDesc)
{
    auto scoresList = getScoresList(mPath, delimiter);
    if (isDesc)
    {
        scoresList.sort(std::greater<Score>());
    }
    else
    {
        scoresList.sort();
    }

    std::list<std::string> results;
    for (auto score : scoresList)
    {
        results.emplace_back(score.ToString());
    }

    return results;
}

std::list<Scores::Score> getScoresList(std::string file_path, char delimiter)
{
    // Вопрос: кажется, что открытия файлового потока - затратная по времени и ресурсам операция.
    // Стоит ли кэшировать открытый поток в полях класса и переисользовать его? А закрывать в деструкторе.
    std::ifstream in_stream{file_path};
    if (!in_stream.is_open())
    {
        throw std::runtime_error(err_read_from_file);
    }

    std::list<Scores::Score> scoresList;
    std::string line;

    while (std::getline(in_stream, line))
    {
        if (line.empty())
        {
            continue;
        }

        int delimiterPosition = line.find(delimiter);
        auto name = line.substr(0, delimiterPosition);
        int attempts_count = std::stoi(line.substr(delimiterPosition + 1, line.size() - 1));

        Scores::Score score{name, attempts_count};

        scoresList.emplace_back(score);
    }

    in_stream.close();
    return scoresList;
}
