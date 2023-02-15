#include "cmath"

#include "statistics/standard_deviation.hpp"

const char *std_name = "std";

StandardDeviation::StandardDeviation() : Mean() {}

void StandardDeviation::update(double next)
{
    Mean::update(next);
    numbers.emplace_back(next);
}

double StandardDeviation::eval() const
{
    double mean = Mean::eval();
    int count = Mean::getCount();

    double sd = 0;
    for (double number : numbers)
    {
        sd += std::pow(number - mean, 2);
    }

    return std::sqrt(sd / count);
}

const char * StandardDeviation::name() const
{
    return std_name;
}
