#pragma once

class IDebugger
{
    public:
        virtual void onGameStateChange(int max_value, int target_value) const = 0;
};