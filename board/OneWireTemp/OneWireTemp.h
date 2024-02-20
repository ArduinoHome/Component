#ifndef ONEWIRETEMP_H
#define ONEWIRETEMP_H

#include <OneWire.h>
#include <DallasTemperature.h>
#include "Timer.h"

#include "FloatInput.h"

class OneWireTemp : public FloatInput
{
private:
    DallasTemperature dallasTemperatureSensor;
    Timer timerScan = Timer();
    double value;
    bool changed = false;
    const uint8_t id;

public:
    OneWireTemp(OneWire *busOnewire, const uint8_t deviceId = 0);
    void setup();
    void loop();
    double GetValue();
    bool HasChanged();
};

#endif