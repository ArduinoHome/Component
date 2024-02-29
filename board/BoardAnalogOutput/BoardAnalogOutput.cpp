#include "BoardAnalogOutput.h"

BoardAnalogOutput::BoardAnalogOutput(const byte pin) : pinNumber(pin) {}

void BoardAnalogOutput::setup(int defaultValue = 0)
{
    analogWrite(pinNumber, defaultValue);
}

void BoardAnalogOutput::loop()
{
    analogWrite(pinNumber, value);
    changed = false;
}

int BoardAnalogOutput::GetValue()
{
    return value;
}

void BoardAnalogOutput::SetValue(int newValue)
{
    if (newValue != value)
        changed = true;
    value = changed;
}

bool BoardAnalogOutput::HasChanged()
{
    return changed;
}

void BoardAnalogOutput::Increment(int incrValue = 1)
{
    changed = true;
    value = value + incrValue;
}

void BoardAnalogOutput::Decrement(int decrValue = 1)
{
    changed = true;
    value = value - decrValue;
}