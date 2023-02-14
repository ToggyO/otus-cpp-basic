#pragma once

#include "mean.hpp"

class StandardDeviation : public Mean
{
    public:
        StandardDeviation();
        void update(double next) override;
        double eval() const override;
        const char * name() const override;

    private:
        double calculateSD();
        double m_sum;
        double m_sd;
        int m_count;
};