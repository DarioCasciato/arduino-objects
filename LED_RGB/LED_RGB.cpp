#include <LED_RGB.h>

// constructor that initializes the RGB LED pin and active level
Hardware::LED_RGB::LED_RGB(uint8_t pin_r, uint8_t pin_g, uint8_t pin_b, activeLevel ActiveLevel = HIGH_ACTIVE)
{
    _pin_R = pin_r;
    _pin_G = pin_g;
    _pin_B = pin_b;
    _activeLevel = ActiveLevel;
}

// Function to set the LED color
Hardware::LED_RGB::set(Colors_RGB colors)
{
    if (_activeLevel == HIGH_ACTIVE)
    {
        analogWrite(_pin_R, colors.r);
        analogWrite(_pin_G, colors.g);
        analogWrite(_pin_B, colors.b);
    }

    if (_activeLevel == LOW_ACTIVE)
    {
        analogWrite(_pin_R, (255 - colors.r));
        analogWrite(_pin_G, (255 - colors.g));
        analogWrite(_pin_B, (255 - colors.b));
    }
}

// Function to turn off LED
Hardware::LED_RGB::off()
{
    if (_activeLevel == HIGH_ACTIVE)
    {
        analogWrite(_pin_R, 0);
        analogWrite(_pin_G, 0);
        analogWrite(_pin_B, 0);
    }

    if (_activeLevel == LOW_ACTIVE)
    {
        analogWrite(_pin_R, 255);
        analogWrite(_pin_G, 255);
        analogWrite(_pin_B, 255);
    }
}