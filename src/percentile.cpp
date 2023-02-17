#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>

#include "statistics/percentile.hpp"

const char *percentile_name = "pct";

Percentile::Percentile(double percent)
    : m_percent(percent), m_name(makeName(percent)) {}

void Percentile::update(double next)
{
    m_numbers.push_back(next);
}

double Percentile::eval() const
{
    if (m_numbers.empty())
    {
        return 0;
    }

    std::sort(m_numbers.begin(), m_numbers.end());

    auto count = m_numbers.size();
    double raw_index = m_percent / 100 * (double)count;

    size_t index = int(std::round(raw_index));
    if (index > count - 1)
    {
        index = int(count - 1);
    }

    return m_numbers[index];
}

const char *Percentile::name() const
{
   return m_name.c_str();
}

std::string Percentile::makeName(double percent) const
{
    std::stringstream ss;
    ss << percentile_name << " ";
    ss << std::fixed;
    ss << std::setprecision(1);
    ss << percent;
    return ss.str();
}