#include <Arduino.h>

namespace Hardware
{
    class Potentiometer
    {
    private:
        enum Direction
        {
            UP,
            DOWN
        };

        uint8_t _pin;
        uint16_t _lastValue;
        Direction _direction;

    public:
        Potentiometer(uint8_t pin, Direction direction);
        uint16_t get();
        uint8_t getPercentage();
        bool hasChanged();
    };
} // namespace Hardware
