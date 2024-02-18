#ifndef BOARDDIGITALINPUT_H
#define BOARDDIGITALINPUT_H

#include <Arduino.h>
#include "DigitalInput.h"

//typedef void (*EventHandler)();

class BoardDigitalInput : public DigitalInput
{
private:
    byte rimbalzo;
    const byte bounceFilter;
    const byte pinNumber;
    bool value;
    //void (*onChangeCallback)(bool);
    bool changed;
    

public:
    BoardDigitalInput(const byte pin,const byte maxBounce);
    void setup();
    void loop();
    bool GetValue();
    //void OnChange(void (*callback)(bool));
    bool HasChanged();
};

#endif