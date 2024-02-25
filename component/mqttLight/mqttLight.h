#ifndef MQTTLIGHT_H
#define MQTTLIGHT_H

#include <PubSubClient.h>
#include "Light.h

class mqttLight : public Light
{
private:
    PubSubClient *pClient;
    const char *device;
    const char *name;
    void publishLightStatus();

public:
    mqttLight(PubSubClient *client, const char *deviceName, const char *lightName, DigitalInput *input, DigitalOutput *output, const bool isButton = true);
    void loop();
    void reconnected();
    void mqttCallback(char *topic, byte *payload, unsigned int length);
};

#endif