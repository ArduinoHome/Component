#ifndef BOARDDIGITALINPUT_H
#define BOARDDIGITALINPUT_H

#include <Arduino.h>
#include "../../dataInterface/DigitalInput.h"

class BoardDigitalInput : public DigitalInput
{
private:
    byte rimbalzo;
    byte maxRimbalzo;
    byte pin;
    bool value;
    

public:
    BoardDigitalInput();
    BoardDigitalInput(byte pin,byte maxRimbalzo);
    void loop();
    bool GetValue();

};

#endif