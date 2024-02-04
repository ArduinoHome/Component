#ifndef BOARDANALOGINPUT_H
#define BOARDANALOGINPUT_H

#include <Arduino.h>
#include "../../dataInterface/AnalogInput.h"


class BoardAnalogInput : public AnalogInput
{
public:
    BoardAnalogInput();
    BoardAnalogInput(byte pin,byte readTimes);
    void loop();
    int GetValue();

private:
    byte readTimes;
    byte pin;
    byte countRead;
    int value;
    unsigned long sum;
};

#endif