#include <string>

#include "scores_manager.h"

std::string Scores::Score::ToString()
{
    return name + ' ' + std::to_string(attempts_count);
}

bool Scores::Score::operator >(const Score& score) const
{
    return attempts_count > score.attempts_count;
}

bool Scores::Score::operator <(const Score& score) const
{
    return attempts_count < score.attempts_count;
}