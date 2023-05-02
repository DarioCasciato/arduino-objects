#include <Button.h>


Hardware::Button* Hardware::Button::buttonList[10] = {nullptr};
uint8_t Hardware::Button::buttonCount = 0;


// Constructor for Button class
Hardware::Button::Button(uint8_t pin)
{
    _pin = pin;
    pinMode(_pin, INPUT);

    buttonList[buttonCount] = this;
    buttonCount++;
}

// Update the button state
void Hardware::Button::updateButton()
{
    buttonEdge.old = buttonEdge.act;
    buttonEdge.act = digitalRead(_pin);
    buttonEdge.edge = buttonEdge.act ^ buttonEdge.old;
    buttonEdge.edge_pos = buttonEdge.edge & buttonEdge.act;
    buttonEdge.edge_neg = buttonEdge.edge & buttonEdge.old;
}

// Update the state of all buttons
void Hardware::Button::updateButtons()
{
    for (uint8_t i = 0; i < buttonCount; i++)
    {
        buttonList[i]->updateButton();
    }
}

// Get the old state of the button
bool Hardware::Button::getOldState()
{
    return buttonEdge.old;
}

// Get the current state of the button
bool Hardware::Button::getActState()
{
    return buttonEdge.act;
}

// Get the button edge state
bool Hardware::Button::getEdge()
{
    return buttonEdge.edge;
}

// Get the positive edge of the button
bool Hardware::Button::getEdgePos()
{
    return buttonEdge.edge_pos;
}

// Get the negative edge of the button
bool Hardware::Button::getEdgeNeg()
{
    return buttonEdge.edge_neg;
}
