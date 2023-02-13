#pragma once

#include <string>

#include "option_type.hpp"

struct Option
{
    OptionType optionType;
    std::string name;
    bool withParam;
};
