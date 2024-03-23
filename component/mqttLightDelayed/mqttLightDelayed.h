#ifndef MQTTLIGHTDELAYED_H
#define MQTTLIGHTDELAYED_H

#include <PubSubClient.h>
#include "LightDelayed.h"

class mqttLightDelayed : public LightDelayed
{
private:
    PubSubClient *pClient;
    const char *device;
    const char *light;
    void publishLightStatus();

public:
    mqttLightDelayed(PubSubClient *client, const char *deviceName,const char *lightName, DigitalInputInterface *input, DigitalOutputInterface *output, const unsigned long delay, const bool isButton = true);
    void loop();
    void reconnected();
    void mqttCallback(char *topic, byte *payload, unsigned int length);
};

#endif