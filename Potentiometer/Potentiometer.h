#include <Arduino.h>

class Potentiometer
{
    enum Direction
    {
        UP,
        DOWN
    };

private:
    uint8_t _pin;
    uint16_t _lastValue;
    Direction _direction;

public:
    Potentiometer(uint8_t pin, Direction direction);
    uint16_t get();
    uint8_t getPercentage();
    bool hasChanged();
};
