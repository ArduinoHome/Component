#ifndef MQTTDIGITALOUTPUT_H
#define MQTTDIGITALOUTPUT_H

#include <PubSubClient.h>
#include <Arduino.h>
#include "DigitalOutputInterface.h"


class mqttDigitalOutput
{
private:
    PubSubClient *pClient;
    const char *device;
    const char *name;
    DigitalOutputInterface *pDigitalOutput;
    void publishStatus();
    

public:
    mqttDigitalOutput(PubSubClient *client, const char *deviceName,const char *digitalOutputName,DigitalOutputInterface *output);
    void loop();
    void reconnected();
    void mqttCallback(char *topic, byte *payload, unsigned int length);

};

#endif