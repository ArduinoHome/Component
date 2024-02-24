#include "BoardAnalogInput.h"

BoardAnalogInput::BoardAnalogInput(const byte pin, const byte maxBounce) : pinNumber(pin), bounceFilter(maxBounce)
{
}

void BoardAnalogInput::setup()
{
    value = analogRead(pinNumber);
}

void BoardAnalogInput::loop()
{
    changed = false;
    if (count < bounceFilter)
    {
        avg += analogRead(pinNumber);
        count++;
    }
    else
    {
        int newValue = avg / bounceFilter;
        count = avg = 0;
        if (value != newValue)
            changed = true;
        value = newValue;
    }
}

int BoardAnalogInput::GetValue()
{
    return value;
}

bool BoardAnalogInput::HasChanged()
{
    return changed;
}