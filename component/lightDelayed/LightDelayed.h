#ifndef LIGHTDELAYED_H
#define LIGHTDELAYED_H


#include "Light.h"
#include "Timer.h"

class LightDelayed : public Light
{
private:
    unsigned long lightDelay;
    Timer timer;

public:
    LightDelayed(DigitalInput *input, DigitalOutput *output, const unsigned long delay, const bool isButton = true);
    void loop();
    void SetValue(bool newValue);
    void Toggle();
};

#endif