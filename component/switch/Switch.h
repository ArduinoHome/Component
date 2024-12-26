#ifndef SWITCH_H
#define SWITCH_H

#include <Arduino.h>
#include "DigitalInputInterface.h"
#include "DigitalOutputInterface.h"

class Switch
{
private:
    const bool button;
    bool changed = false;
    DigitalInputInterface *pDigitalInput;
    DigitalOutputInterface *pDigitalOutput;

public:
    Switch(DigitalInputInterface *input, DigitalOutputInterface *output, const bool isButton = true);
    void loop();
    bool GetValue();
    bool HasChanged();
    void SetValue(bool newValue);
    void Toggle();
};

#endif