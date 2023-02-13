#include "debugger.hpp"

void Debugger::onGameStateChange(int max_value, int target_value) const
{
    std::cout << "max value " << max_value << std::endl;
    std::cout << "target value " << target_value << std::endl;
}
