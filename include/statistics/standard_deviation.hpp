#pragma once

#include <vector>

#include "mean.hpp"

class StandardDeviation : public Mean
{
    public:
        StandardDeviation();
        void update(double next) override;
        double eval() const override;
        const char * name() const override;

    private:
        std::vector<double> numbers;
};