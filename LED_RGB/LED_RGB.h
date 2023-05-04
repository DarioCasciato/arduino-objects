#include <Arduino.h>

namespace Hardware
{
    enum activeLevel
    {
        COMMON_ANODE,
        COMMON_CATHODE
    };

    typedef union
    {
        uint32_t hex_code;
        struct
        {
            uint8_t r;
            uint8_t g;
            uint8_t b;
        } components;
    } Colors_RGB;

    class LED_RGB
    {
    private:
        uint8_t _pin_R;
        uint8_t _pin_G;
        uint8_t _pin_B;
        activeLevel _activeLevel;

    public:
        LED_RGB(uint8_t pin_r, uint8_t pin_g, uint8_t pin_b, activeLevel ActiveLevel = COMMON_CATHODE);
        void set(Colors_RGB colors);
        void off();
    };
}
