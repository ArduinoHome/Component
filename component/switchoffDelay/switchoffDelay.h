#ifndef SWITCHOFFDELAY_H
#define SWITCHOFFDELAY_H


#include "DigitalOutputInterface.h"
#include "Timer.h"

class switchoffDelay
{
private:
    unsigned long pDelay;
    Timer timer;
    DigitalOutputInterface *pOutput;

public:
    switchoffDelay(DigitalOutputInterface *output, const unsigned long delay);
    void loop();
    void SetValue(bool newValue);
    void Toggle();
    bool GetValue();
};

#endif