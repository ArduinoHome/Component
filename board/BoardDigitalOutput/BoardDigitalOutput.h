#ifndef BOARDDIGITALOUTPUT_H
#define BOARDDIGITALOUTPUT_H

#include <Arduino.h>
#include "DigitalOutput.h"

class BoardDigitalOutput : public DigitalOutput
{
private:
    const bool reverseOutput;
    const byte pinNumber;
    bool value;
    bool changed;

public:
    //BoardDigitalOutput(){};
    BoardDigitalOutput(const byte pin,const bool reverse);
    void setup();
    void loop();
    bool GetValue();
    void SetValue(bool newValue);
    void SetOn();
    void SetOff();
    void Toggle();
    bool HasChanged();

};

#endif

