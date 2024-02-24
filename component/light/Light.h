#ifndef LIGHT_H
#define LIGHT_H

#include <Arduino.h>
#include "DigitalInput.h"
#include "DigitalOutput.h"

class Light
{
private:
    const bool button;
    bool changed = false;
    DigitalInput *pDigitalInput;
    DigitalOutput *pDigitalOutput;

public:
    Light(DigitalInput *input, DigitalOutput *output, const bool isButton = true);
    void loop();
    bool GetValue();
    bool HasChanged();
    void SetValue(bool newValue);
    void Toggle();
};

#endif