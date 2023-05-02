#include <Arduino.h>

class Timer
{
    private:
        uint32_t _startTicks = 0;
        uint32_t _delta = 0;

    public:
        void start();
        bool elapsed(uint32_t ms);
        uint32_t remaining(uint32_t ms);
        uint32_t elapsedStart();
}
