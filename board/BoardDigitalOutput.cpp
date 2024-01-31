#include "BoardDigitalOutput.h"

BoardDigitalOutput::BoardDigitalOutput() {}

BoardDigitalOutput::BoardDigitalOutput(byte pin, bool reverse)
{
    if (reverse)
        digitalWrite(pin, HIGH);
    else
        digitalWrite(pin, LOW);

    pinMode(pin, OUTPUT);
}

void BoardDigitalOutput::loop()
{
    if (reverse)
        digitalWrite(pin, !value);
    else
        digitalWrite(pin, value);
}

bool BoardDigitalOutput::GetValue()
{
    return value;
}

void BoardDigitalOutput::SetValue(bool value)
{
    this->value = value;
}

void BoardDigitalOutput::SetOn()
{
    this->value = true;
}

void BoardDigitalOutput::SetOff()
{
    this->value = false;
}

void BoardDigitalOutput::Toggle()
{
    this->value = !value;
}