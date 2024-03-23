#ifndef BOARDANALOGINPUT_H
#define BOARDANALOGINPUT_H

#include <Arduino.h>
#include "AnalogInputInterface.h"


class BoardAnalogInput : public AnalogInputInterface
{
private:
    const byte bounceFilter;
    const byte pinNumber;
    byte count;
    int value;
    bool changed;
    long avg;


public:
    BoardAnalogInput(const byte pin,const byte maxBounce);
    void setup();
    void loop();
    int GetValue();
    bool HasChanged();
};

#endif