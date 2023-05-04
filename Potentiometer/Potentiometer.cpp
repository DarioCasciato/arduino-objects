#include <Potentiometer.h>

Hardware::Potentiometer::Potentiometer(uint8_t pin, Direction direction)
{
    _pin = pin;
    _direction = direction;
}

uint16_t Hardware::Potentiometer::get()
{
    _lastValue = analogRead(_pin);

    if (_direction == UP)
        return analogRead(_pin);

    if (_direction == DOWN)
        return 1023 - analogRead(_pin);
}

uint8_t Hardware::Potentiometer::getPercentage()
{
    _lastValue = analogRead(_pin);

    if (_direction == UP)
        return map(analogRead(_pin), 0, 1023, 0, 100);

    if (_direction == DOWN)
        return map(1023 - analogRead(_pin), 0, 1023, 0, 100);
}

bool Hardware::Potentiometer::hasChanged()
{
    if (_lastValue != analogRead(_pin))
    {
        _lastValue = analogRead(_pin);
        return 1;
    }

    return 0;
}