#ifndef MQTTDIGITALOUTPUT_H
#define MQTTDIGITALOUTPUT_H

#include <Ethernet.h>
#include <PubSubClient.h>
#include <Arduino.h>
#include "DigitalOutput.h"


class mqttDigitalOutput
{
private:
    PubSubClient *pClient;
    const char *device;
    const char *name;
    DigitalOutput *pDigitalOutput;
    void publishStatus();
    

public:
    mqttDigitalOutput(PubSubClient *client, const char *deviceName,const char *digitalOutputName,DigitalOutput *output);
    void loop();
    void reconnected();
    void mqttCallback(char *topic, byte *payload, unsigned int length);

};

#endif