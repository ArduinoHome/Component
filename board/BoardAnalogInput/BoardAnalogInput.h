#ifndef BOARDANALOGINPUT_H
#define BOARDANALOGINPUT_H

#include <Arduino.h>
#include "AnalogInput.h"


class BoardAnalogInput : public AnalogInput
{
private:
    const byte readTimes;
    const byte pinNumber;
    byte bounceFilter;
    int value;
    bool changed;
    long rimbalzo;


public:
    BoardAnalogInput(const byte pin,const byte readTimes);
    void setup();
    void loop();
    int GetValue();
    bool HasChanged();
};

#endif