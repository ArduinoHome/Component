#ifndef BOARDDIGITALOUTPUT_H
#define BOARDDIGITALOUTPUT_H

#include <Arduino.h>
#include "DigitalOutput.h"

class BoardDigitalOutput : public DigitalOutput
{
private:
    bool reverse;
    byte pin;
    bool value;
    

public:
    BoardDigitalOutput();
    BoardDigitalOutput(byte pin,bool reverse);
    void loop();
    bool GetValue();
    void SetValue(bool value);
    void SetOn();
    void SetOff();
    void Toggle();

};

#endif

