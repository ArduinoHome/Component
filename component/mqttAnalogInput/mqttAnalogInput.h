#ifndef MQTTANALOGINPUT_H
#define MQTTANALOGINPUT_H

#include <PubSubClient.h>
#include <Arduino.h>
#include "AnalogInput.h"



class mqttAnalogInput
{
private:
    PubSubClient *pClient;
    const char *device;
    const char *name;
    AnalogInput *pAnalogInput;
    void publishStatus();
    

public:
    mqttAnalogInput(PubSubClient *client, const char *deviceName,const char *analogInputName, AnalogInput *input);
    void loop();
    void reconnected();
    void mqttCallback(char *topic, byte *payload, unsigned int length);

};

#endif