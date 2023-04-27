#include <Arduino.h>

namespace Hardware
{
    class Button
    {
        private:
            uint8_t _pin;
            static Button* buttonList[10];
            static uint8_t buttonCount;

            struct edge_t
            {
                uint8_t old;
                uint8_t act;
                uint8_t edge;
                uint8_t edge_pos;
                uint8_t edge_neg;
            } buttonEdge;

        public:
            Button(uint8_t pin);

            void updateButton();
            static void updateButtons();

            bool getOldState();
            bool getActState();
            bool getEdge();
            bool getEdgePos();
            bool getEdgeNeg();
    };
}
