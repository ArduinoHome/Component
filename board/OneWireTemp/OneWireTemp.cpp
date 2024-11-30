#include "OneWireTemp.h"

#define SAMPLESCOUNT 10

OneWireTemp::OneWireTemp(OneWire *busOnewire, const uint8_t* sensorAddress) : sensorId(sensorAddress)
{
    dallasTemperatureSensor = DallasTemperature(busOnewire);
}

void OneWireTemp::setup()
{
    dallasTemperatureSensor.begin();
    timerScan.Start(60000, true);
    dallasTemperatureSensor.requestTemperatures();
    value = dallasTemperatureSensor.getTempC(sensorId);
    //if (value == DEVICE_DISCONNECTED_C) //
}

void OneWireTemp::loop()
{
    changed = false;
    if (timerScan.Elapsed())
    {
        dallasTemperatureSensor.requestTemperatures();
        double newvalue = dallasTemperatureSensor.getTempC(sensorId);
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

/*
void printOneWire()
{
  byte addr[8];

  // Cerca il primo dispositivo sulla rete OneWire
  onewire.reset_search();
  while (onewire.search(addr))
  {
    // Stampa l'ID del dispositivo trovato
    prt("Dispositivo trovato: ");
    for (int i = 0; i < 8; i++)
    {
      if (addr[i] < 16)
        prt('0'); // Aggiunge uno zero per formattare
      prt(addr[i], HEX);
    }
    prtln();
  }
}

*/