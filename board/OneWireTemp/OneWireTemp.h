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
    Timer timerScan;
    double value;
    uint8_t deviceId;

public:
    OneWireTemp();
    OneWireTemp(OneWire *busOnewire, uint8_t deviceId = 0);
    void loop();
    double GetValue();
};

#endif