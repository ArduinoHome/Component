#ifndef ONEWIRETEMP_H
#define ONEWIRETEMP_H

#include <OneWire.h>
#include <DallasTemperature.h>
#include "Timer.h"

#include "FloatInputInterface.h"

class OneWireTemp : public FloatInputInterface
{
private:
    DallasTemperature dallasTemperatureSensor;
    Timer timerScan = Timer();
    double value;
    bool changed = false;
    const uint8_t* sensorId;

public:
    OneWireTemp(OneWire *busOnewire, const uint8_t* sensorAddress);
    void setup();
    void loop();
    double GetValue();
    bool HasChanged();
};

#endif