#ifndef MQTTLIGHTDELAYED_H
#define MQTTLIGHTDELAYED_H

#include <PubSubClient.h>
#include <Arduino.h>
#include "DigitalInput.h"
#include "DigitalOutput.h"
#include "Timer.h"

class mqttLightDelayed
{
private:
    unsigned long lightDelay;
    PubSubClient *pClient;
    const char *device;
    const char *light;
    DigitalInput *pDigitalInput;
    DigitalOutput *pDigitalOutput;
    Timer timer;
    void publishLightStatus();

public:
    mqttLightDelayed(PubSubClient *client, const char *deviceName,const char *lightName, DigitalInput *input, DigitalOutput *output, const unsigned long delay);
    void loop();
    void reconnected();
    void mqttCallback(char *topic, byte *payload, unsigned int length);
};

#endif