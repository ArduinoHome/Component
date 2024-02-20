#include "OneWireTemp.h"

#define SAMPLESCOUNT 10

OneWireTemp::OneWireTemp(OneWire *busOnewire, const uint8_t deviceId = 0) : id(deviceId)
{
    dallasTemperatureSensor = DallasTemperature(busOnewire);
}

void OneWireTemp::setup()
{
    dallasTemperatureSensor.begin();
    timerScan.Start(60000, true);
    dallasTemperatureSensor.requestTemperatures();
    value = dallasTemperatureSensor.getTempCByIndex(id);
}

void OneWireTemp::loop()
{
    changed = false;
    if (timerScan.Elapsed())
    {
        dallasTemperatureSensor.requestTemperatures();
        double newvalue = dallasTemperatureSensor.getTempCByIndex(id);
        if (newvalue != value)
            changed = true;
        value = newvalue;
    }
}

double OneWireTemp::GetValue()
{
    return value;
}

bool OneWireTemp::HasChanged()
{
    return changed;
}