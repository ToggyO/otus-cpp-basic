#include <algorithm>
#include <cmath>
#include <iostream>
#include <sstream>

#include "statistics/percentile.hpp"

const char *percentile_name = "pct";

Percentile::Percentile(double percent)
    : m_percent(percent), m_name(initializeName(percent)) {}

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

    std::vector<double> temp(m_numbers);
    std::sort(temp.begin(), temp.end());

    auto count = (double)temp.size();
    double raw_index = m_percent / 100 * count; // Может быть переполнение? Как правильно работать с size_t вместе с другими числовыми типами?

    int index = int(std::round(raw_index));
    if (index > count - 1)
    {
        index = int(count - 1);
    }

    return temp[index];
}

const char *Percentile::name() const
{
    // Знаю, что это неправильно. Но не могу понятЬ как сделать лучше
    std::stringstream ss;
    ss << percentile_name << m_percent;
    return ss.str().c_str();
}

const char *Percentile::initializeName(double percent)
{
    // ВОПРОС: Если я не првожу такую же операцию в методе name(), то m_name будет пустой
    // Инициализаация не работает. Почему?

    // ВОПРОС: как лучше объединить char* и int?
    std::stringstream ss;
    ss << percentile_name << percent;

    auto k = ss.str();
    auto c = k.c_str();
    m_name = c;

    return m_name;
}