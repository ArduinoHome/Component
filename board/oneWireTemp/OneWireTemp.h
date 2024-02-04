#ifndef ONEWIRETEMP_H
#define ONEWIRETEMP_H

#include <OneWire.h>
#include <DallasTemperature.h>
#include "../../tool/timer/Timer.h"

#include "../../dataInterface/FloatInput.h"

class OneWireTemp : public FloatInput
{
private:
    OneWire busOnewire;
    DallasTemperature dallasTemperatureSensor;
    Timer timerScan;
    double value;
    uint8_t deviceId;

public:
    OneWireTemp();
    OneWireTemp(uint8_t pinOneWire,uint8_t deviceId =0);
    void loop();
    double GetValue();

};

#endif