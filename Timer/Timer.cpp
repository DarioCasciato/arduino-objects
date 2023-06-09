// =========================================
// arduino-objects | Timer
// =========================================

#include "Timer.h"

void Timer::start()
{
    _startTicks = millis();
}

bool Timer::elapsed(uint32_t ms)
{
    _delta = millis() - _startTicks;

    if (_delta < ms)
        return _delta >= ms;
}

uint32_t Timer::remaining(uint32_t ms)
{
    _delta = millis() - _startTicks;

    if (_delta < ms)
        return ms - _delta;
}

uint32_t Timer::elapsedStart()
{
    return millis() - _startTicks;
}
