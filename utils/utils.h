#pragma once

#include <iostream>

#include "../counter.h"

namespace utils
{
    void print_topk(std::ostream& stream, const Counter& counter, const size_t k);

    std::string to_lower(const std::string &str);
}
