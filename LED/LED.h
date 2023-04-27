#include <Arduino.h>

namespace Hardware
{
    enum activeLevel {LOW_ACTIVE, HIGH_ACTIVE};
    enum level {OFF, ON};

    class LED
    {
        private:
            uint8_t _pin;
            activeLevel _activeLevel;

        public:
            LED(uint8_t pin, activeLevel ActiveLevel = HIGH_ACTIVE);
            void set(bool setLevel);
            bool get();
            void toggle();
            void on();
            void off();
    };
}
