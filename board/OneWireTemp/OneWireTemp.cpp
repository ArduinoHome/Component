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
  Serial.begin(9600);
  while (onewire.search(addr))
  {
    // Stampa l'ID del dispositivo trovato
    Serial.print("Dispositivo trovato: ");
    for (int i = 0; i < 8; i++)
    {
      if (addr[i] < 16)
        Serial.print('0'); // Aggiunge uno zero per formattare
      Serial.print(addr[i], HEX);
    }
    Serial.println();
  }
}

*/