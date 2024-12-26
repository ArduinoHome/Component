#ifndef SWITCHDELAYED_H
#define SWITCHDELAYED_H


#include "Switch.h"
#include "Timer.h"

class SwitchDelayed : public Switch
{
private:
    unsigned long switchDelay;
    Timer timer;

public:
    SwitchDelayed(DigitalInputInterface *input, DigitalOutputInterface *output, const unsigned long delay, const bool isButton = true);
    void loop();
    void SetValue(bool newValue);
    void Toggle();
};

#endif