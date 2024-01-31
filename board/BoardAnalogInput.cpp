#include "BoardAnalogInput.h"

BoardAnalogInput ::BoardAnalogInput() {}

BoardAnalogInput::BoardAnalogInput(byte pin, byte readTimes)
{
    this->readTimes = readTimes;
    value = analogRead(pin);
}

void BoardAnalogInput::loop()
{

    if (countRead < readTimes)
    {
        sum += (unsigned long)analogRead(pin); // Legge la Att_Pos in cui si trova il carro
        countRead++;
    }
    else
    {
        value = sum / readTimes;
        countRead = sum = 0;
    }
}

int BoardAnalogInput::GetValue()
{
    return value;
}