#include "BoardAnalogInput.h"

BoardAnalogInput::BoardAnalogInput(const byte pin, const byte readTimes) : pinNumber(pin), bounceFilter(readTimes)
{
}

void BoardAnalogInput::setup()
{
    value = analogRead(pin);
}

void BoardAnalogInput::loop()
{
    changed = false;
    if (countRead < readTimes)
    {
        sum += analogRead(pin);
        countRead++;
    }
    else
    {
        int newValue = sum / readTimes;
        countRead = sum = 0;
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