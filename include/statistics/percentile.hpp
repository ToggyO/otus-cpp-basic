#pragma once

#include <vector>

#include "statistics.hpp"

class Percentile : public IStatistics
{
    public:
        explicit Percentile(double percent);
        void update(double next) override;
        double eval() const override;
        const char * name() const override;

    private:
        double percent;
        std::vector<double> numbers;
        const char* m_name;
};