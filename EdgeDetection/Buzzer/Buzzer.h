#include <Arduino.h>

class Buzzer
{
private:
    uint8_t _pin;

public:
    Buzzer(uint8_t pin);
    void play(uint16_t freq);
    void pause();
};
