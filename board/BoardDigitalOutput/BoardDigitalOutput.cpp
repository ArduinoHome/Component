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
    value = newValue;
}

void BoardDigitalOutput::SetOn()
{
    value = true;
}

void BoardDigitalOutput::SetOff()
{
    value = false;
}

void BoardDigitalOutput::Toggle()
{
    value = !value;
}