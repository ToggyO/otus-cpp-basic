#include <iostream>
#include <limits>

#include "statistics/max.hpp"

const char *max_name = "max";

Max::Max() : m_max(std::numeric_limits<double>::min()) {}

void Max::update(double next)
{
    if (next > m_max)
    {
        m_max = next;
    }
}

double Max::eval() const
{
    return m_max;
}

const char *Max::name() const
{
    return max_name;
}