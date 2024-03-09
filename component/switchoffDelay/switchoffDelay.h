#ifndef SWITCHOFFDELAY_H
#define SWITCHOFFDELAY_H


#include "DigitalOutput.h"
#include "Timer.h"

class switchoffDelay
{
private:
    unsigned long pDelay;
    Timer timer;
    DigitalOutput *pOutput;

public:
    switchoffDelay(DigitalOutput *output, const unsigned long delay);
    void loop();
    void SetValue(bool newValue);
    void Toggle();
    bool GetValue();
};

#endif