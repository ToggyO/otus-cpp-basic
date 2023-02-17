#pragma once

#include <cstddef>

#include "statistics.hpp"

class Mean : public IStatistics
{
    public:
        Mean();
        void update(double next) override;
        double eval() const override;
        const char * name() const override;

    private:
        std::size_t m_count;
        double m_sum;
};