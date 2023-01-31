#pragma once

#include <fstream>
#include <list>

namespace Scores
{
class ScoresManager
{
public:
    ScoresManager(const std::string &file_path);
    int WriteScore(const std::string &user_name, ushort attempts_count);
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
    score_username_equality(const std::string &n);
    bool operator () (const Scores::Score &s);
private:
    std::string name;
};
}

std::list<Scores::Score> getScoresList(std::string file_path, char delimiter);

void appendScore(std::ofstream &out_stream, const std::string &user_name, const ushort attempts_count, const char delimiter);

void rewriteScores(std::ofstream &out_stream, const std::list<Scores::Score> &scores, const char delimiter);