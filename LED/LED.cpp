#include <LED.h>

// constructor that initializes the LED pin and active level
Hardware::LED::LED(uint8_t pin, activeLevel ActiveLevel = HIGH_ACTIVE)
{
    _pin = pin;
    _activeLevel = ActiveLevel;

    pinMode(_pin, INPUT);

    // set the initial state of the LED based on active level
    if(_activeLevel == LOW_ACTIVE) digitalWrite(_pin, HIGH);
    else digitalWrite(_pin, LOW);
}

// function to set the LED state based on the active level
void Hardware::LED::set(level setLevel)
{
    if(_activeLevel == LOW_ACTIVE) digitalWrite(_pin, ~setLevel);
    else digitalWrite(_pin, setLevel);
}

// function to get the current state of the LED
bool Hardware::LED::get()
{
    return digitalRead(_pin) == _activeLevel;
}

// function to toggle the LED state
void Hardware::LED::toggle()
{
    digitalWrite(_pin, digitalRead(_pin) ^ 1);
}

// function to turn on the LED
void Hardware::LED::on()
{
    if(_activeLevel == LOW_ACTIVE) digitalWrite(_pin, LOW);
    else digitalWrite(_pin, HIGH);
}

// function to turn off the LED
void Hardware::LED::off()
{
    if(_activeLevel == LOW_ACTIVE) digitalWrite(_pin, HIGH);
    else digitalWrite(_pin, LOW);
}
