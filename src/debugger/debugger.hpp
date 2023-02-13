#include <iostream>

#include "../debugger.h"

class Debugger : public IDebugger
{
    public:
        void onGameStateChange(int max_value, int target_value) const override;
};