#include "BoardDigitalOutput.h"

BoardDigitalOutput::BoardDigitalOutput(const byte pin, const bool reverse) : pinNumber(pin), reverseOutput(reverse)
{
}

void BoardDigitalOutput::setup()
{
    if (reverseOutput)
        digitalWrite(pinNumber, HIGH);
    else
        digitalWrite(pinNumber, LOW);

    pinMode(pinNumber, OUTPUT);
}

void BoardDigitalOutput::loop()
{
    changed = false;
    if (reverseOutput)
        digitalWrite(pinNumber, !value);
    else
        digitalWrite(pinNumber, value);
}

bool BoardDigitalOutput::GetValue()
{
    return value;
}

void BoardDigitalOutput::SetValue(bool newValue)
{
    if (value != newValue)
        changed = true;
    value = newValue;
}

void BoardDigitalOutput::SetOn()
{
    if (value != true)
        changed = true;
    value = true;
}

void BoardDigitalOutput::SetOff()
{
    if (value != false)
        changed = true;
    value = false;
}

void BoardDigitalOutput::Toggle()
{
    changed = true;
    value = !value;
}