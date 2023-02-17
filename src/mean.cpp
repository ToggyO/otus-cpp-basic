#include "statistics/mean.hpp"

const char *mean_name = "mean";

Mean::Mean() : m_count(0), m_sum(0.0) {}

void Mean::update(double next)
{
    m_sum += next;
    m_count++;
}

double Mean::eval() const
{
    return m_sum / (double)m_count;
}

const char *Mean::name() const
{
    return mean_name;
}