#ifndef LIGHT_H
#define LIGHT_H

#include <PubSubClient.h>
#include <Arduino.h>
#include "DigitalInput.h"
#include "DigitalOutput.h"


class Light
{
private:
    PubSubClient *pClient;
    const char *device;
    const char *light;
    DigitalInput *pDigitalInput;
    DigitalOutput *pDigitalOutput;
    void publishLightStatus();
    

public:
    Light(PubSubClient *client, const char *deviceName,const char *lightName, DigitalInput *input, DigitalOutput *output);
    void loop();
    void reconnected();
    void mqttCallback(char *topic, byte *payload, unsigned int length);

};

#endif