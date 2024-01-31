#include "BoardAnalogOutput.h"

BoardAnalogOutput ::BoardAnalogOutput() {}

BoardAnalogOutput::BoardAnalogOutput(byte pin)
{
    this->pin = pin;
}

void BoardAnalogOutput::loop()
{
    analogWrite(pin, value);
}

int BoardAnalogOutput::GetValue()
{
    return value;
}

void BoardAnalogOutput::SetValue(int value)
{
    this->value = value;
}