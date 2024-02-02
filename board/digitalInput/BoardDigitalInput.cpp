#include "BoardDigitalInput.h"

BoardDigitalInput::BoardDigitalInput(){}

BoardDigitalInput::BoardDigitalInput(byte pin, byte maxRimbalzo)
{
    this->maxRimbalzo = maxRimbalzo;
    this->pin = pin;
    pinMode(pin, INPUT_PULLUP);
}

/* void DigitalInput::loop()
{
    bool value = false;

    if (!digitalRead(pin))
    {
        if (rimbalzo < maxRimbalzo)
            rimbalzo++;
        else
            value = true;
    }
    else
        rimbalzo = 0;

    return value;
}
 */

void BoardDigitalInput::loop()
{
    if (!digitalRead(pin))
    {
        if (rimbalzo < maxRimbalzo)
            rimbalzo++;
        else
            this->value = true;
    }
    else
    {
        rimbalzo = 0;
        this->value = false;
    }
}

bool BoardDigitalInput::GetValue()
{
    return value;
}