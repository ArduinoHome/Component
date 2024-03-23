#ifndef MQTTANALOGINPUT_H
#define MQTTANALOGINPUT_H

#include <PubSubClient.h>
#include <Arduino.h>
#include "AnalogInputInterface.h"
#include "Timer.h"



class mqttAnalogInput
{
private:
    PubSubClient *pClient;
    const char *device;
    const char *name;
    AnalogInputInterface *pAnalogInput;
    void publishStatus();
    Timer scan;
    

public:
    mqttAnalogInput(PubSubClient *client, const char *deviceName,const char *analogInputName, AnalogInputInterface *input,const unsigned long scaninterval);
    void loop();
    void reconnected();
    void mqttCallback(char *topic, byte *payload, unsigned int length);

};

#endif