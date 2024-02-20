#ifndef BOARDDIGITALINPUT_H
#define BOARDDIGITALINPUT_H

#include <Arduino.h>
#include "DigitalInput.h"


class BoardDigitalInput : public DigitalInput
{
private:
    byte rimbalzo;
    const byte bounceFilter;
    const byte pinNumber;
    bool value;
    bool changed;
    

public:
    BoardDigitalInput(const byte pin,const byte maxBounce);
    void setup();
    void loop();
    bool GetValue();
    bool HasChanged();
};

#endif