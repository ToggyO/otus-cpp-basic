#include <iostream>
#include <limits>

#include "statistics/min.hpp"

Min::Min() : m_min{std::numeric_limits<double>::min()} {}

void Min::update(double next) override {
    if (next < m_min) {
        m_min = next;
    }
}

double Min::eval() const
{
    return m_min;
}

const char *Min::name() const override
{
    return "min";
}
