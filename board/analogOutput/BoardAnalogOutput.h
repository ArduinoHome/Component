#ifndef BOARDANALOGOUTPUT_H
#define BOARDANALOGOUTPUT_H

#include <Arduino.h>
#include "../../dataInterface/AnalogOutput.h"


class BoardAnalogOutput : public AnalogOutput
{
public:
    BoardAnalogOutput();
    BoardAnalogOutput(byte pin);
    void loop();
    int GetValue();
    void SetValue(int value);

private:
    byte pin;
    int value;
};

#endif