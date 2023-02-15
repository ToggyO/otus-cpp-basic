#include <algorithm>
#include <cmath>
#include <iostream>
#include <cstring>

#include "statistics/percentile.hpp"

const char *percentile_name = "pct";

Percentile::Percentile(double percent) : percent(percent), m_name()
{
    // ВОПРОС: как лучше объединить char* и int?
    m_name = (std::string(percentile_name) + std::to_string(percent)).c_str();
}

void Percentile::update(double next)
{
    numbers.push_back(next);
}

double Percentile::eval() const
{
    if (numbers.empty())
    {
        return 0;
    }

    std::vector<double> temp(numbers);
    std::sort(temp.begin(), temp.end());

    auto count = (double)temp.size();
    double raw_index = percent / 100 * count; // Может быть переполнение? Как правильно работать с size_t вместе с другими числовыми типами?

    int index = int(std::round(raw_index));
    if (index > count - 1)
    {
        index = int(count - 1);
    }

    return temp[index];
}

const char *Percentile::name() const
{
    return m_name;
}