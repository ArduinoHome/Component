#include "OneWireTemp.h"

OneWireTemp::OneWireTemp() {}

OneWireTemp::OneWireTemp(uint8_t pinOneWire, uint8_t deviceId = 0)
{
    this->deviceId = deviceId;
    busOnewire.begin(pinOneWire);
    dallasTemperatureSensor = DallasTemperature(&busOnewire);
    dallasTemperatureSensor.begin();
    timerScan.Start(1000, true);
    dallasTemperatureSensor.requestTemperatures();
    value = dallasTemperatureSensor.getTempCByIndex(deviceId);
}

void OneWireTemp::loop()
{
    if (timerScan.Elapsed())
    {
        dallasTemperatureSensor.requestTemperatures();
        double a = 0;

        for (int samples = 0; samples < 10; samples++)
        {
            a += dallasTemperatureSensor.getTempCByIndex(deviceId);
        }
        value = a / 10;
    }
}

double OneWireTemp::GetValue()
{
    return value;
}