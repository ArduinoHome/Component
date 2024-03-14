#include "BoardDigitalInput.h"

BoardDigitalInput::BoardDigitalInput(byte pin, byte maxBounce, const bool revert = false) : pinNumber(pin), bounceFilter(maxBounce), pRevert(revert)
{
}

void BoardDigitalInput::setup()
{
    pinMode(pinNumber, INPUT_PULLUP);
    // changed = false;
}

void BoardDigitalInput::loop()
{
    changed = false;
    if (!digitalRead(pinNumber))
    {
        if (rimbalzo < bounceFilter)
            rimbalzo++;
        else if (value != true)
        {
            value = true;
            // if (onChangeCallback != NULL)
            //     onChangeCallback(value);
            changed = true;
        }
    }
    else if (value != false)
    {
        rimbalzo = 0;
        // if (onChangeCallback != NULL)
        //         onChangeCallback(value);
        value = false;
        changed = true;
    }
}

bool BoardDigitalInput::GetValue()
{
    if (!pRevert)
        return value;
    else
        return !value;
}

/* void BoardDigitalInput::OnChange(void (*callback)(bool))
{
    onChangeCallback = callback;
} */

bool BoardDigitalInput::HasChanged()
{
    return changed;
}