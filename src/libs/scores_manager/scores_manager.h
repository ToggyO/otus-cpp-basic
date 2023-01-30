#pragma once

#include <fstream>
#include <list>

namespace Scores
{
class ScoresManager
{
public:
    ScoresManager(std::string file_path);
    int WriteScore(std::string user_name, ushort attempts_count);
    std::list<std::string> GetScoresList(bool isDesc = false);
private:
    std::string mPath;
    static const char delimiter;
};

struct Score
{
public:
    const std::string name;
    int attempts_count;

    std::string ToString();
    bool operator >(const Score& score) const;
    bool operator <(const Score& score) const;
};

struct score_username_equality
{
public:
    score_username_equality(const std::string& n);
    bool operator () (const Scores::Score& s);
private:
    std::string name;
};
}