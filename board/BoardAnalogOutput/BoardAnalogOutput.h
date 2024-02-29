#ifndef BOARDANALOGOUTPUT_H
#define BOARDANALOGOUTPUT_H

#include <Arduino.h>
#include "AnalogOutput.h"


class BoardAnalogOutput : public AnalogOutput
{
private:
    const byte pinNumber;
    bool changed;
    int value;

public:
    BoardAnalogOutput(const byte pin);
    void setup(int defaultValue=0);
    void loop();
    int GetValue();
    void SetValue(int newValue);
    bool HasChanged();
    void Increment(int incrValue = 1);
    void Decrement(int decrValue = 1);
};

#endif