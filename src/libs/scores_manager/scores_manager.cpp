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

Scores::ScoresManager::ScoresManager(const std::string &file_path)
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

bool Scores::ScoresManager::validateUserName(const std::string &user_name)
{
    size_t delimiterPosition = user_name.find(delimiter, 0);
    if (delimiterPosition != std::string::npos)
    {
        // Можно применить тернарный оператор, но я хочу вывести сообщение с текстом ошибки
        std::cout << err_forbidden_char << ' ' << '`' << delimiter << '`' << std::endl;
        return false;
    }

    return true;
}

int Scores::ScoresManager::WriteScore(const std::string &user_name, ushort attempts_count)
{
    std::ofstream out_stream;

    auto scores = getScoresList(mPath, delimiter);
    auto user_score_iter = std::find_if(scores.begin(), scores.end(), [&] (const Score& s) {return user_name == s.name;});
    if ((user_score_iter != scores.end()) && (user_score_iter->attempts_count > attempts_count))
    {
        out_stream.open(mPath, std::ofstream::out | std::ofstream::trunc);
        if (out_stream.fail())
        {
            throw std::runtime_error(err_write_to_file);
        }

        user_score_iter->attempts_count = attempts_count;
        rewriteScores(out_stream, scores, delimiter); 
    }
    else
    {
        out_stream.open(mPath, std::ofstream::app);
        if (out_stream.fail())
        {
            throw std::runtime_error(err_write_to_file);
        }

        appendScore(out_stream, user_name, attempts_count, delimiter);
    }

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

std::list<Scores::Score> Scores::getScoresList(std::string file_path, char delimiter)
{
    std::ifstream in_stream{file_path};
    if (!in_stream.is_open() || in_stream.fail())
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

void Scores::appendScore(std::ofstream &out_stream, const std::string &user_name, const ushort attempts_count, const char delimiter)
{
    out_stream << user_name << delimiter;
    out_stream << attempts_count << std::endl;
}

void Scores::rewriteScores(std::ofstream &out_stream, const std::list<Scores::Score> &scores, const char delimiter)
{
    for (const auto &score : scores)
    {
        appendScore(out_stream, score.name, score.attempts_count, delimiter);
    }
}