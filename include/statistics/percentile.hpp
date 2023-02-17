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
        std::string makeName(double percent) const;

        mutable std::vector<double> m_numbers;
        double m_percent;
        std::string m_name;
};