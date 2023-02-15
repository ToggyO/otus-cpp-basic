#pragma once

#include "statistics.hpp"

class Mean : public IStatistics
{
    public:
        Mean();
        void update(double next) override;
        double eval() const override;
        const char * name() const override;

    protected:
        int getCount() const { return m_count; };

    private:
        int m_count;
        double m_sum;
};