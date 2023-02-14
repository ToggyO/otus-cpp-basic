#include "statistics/standard_deviation.hpp"

StandardDeviation::StandardDeviation() : m_sd(0.0), m_sum(0.0), m_count(0) {}

void StandardDeviation::update(double next)
{
    m_sum += next;
    m_count++;
}

double StandardDeviation::eval() const
{
    double mean = m_sum 
    return 0;
}

const char * StandardDeviation::name() const
{
    return "std";
}