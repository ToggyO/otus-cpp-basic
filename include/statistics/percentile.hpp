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
        const char *initializeName(double percent);
        double m_percent;
        std::vector<double> m_numbers;
        const char* m_name;
};