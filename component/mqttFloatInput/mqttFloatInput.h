#ifndef MQTTFLOATINPUT_H
#define MQTTFLOATINPUT_H

#include <PubSubClient.h>
#include <Arduino.h>
#include "FloatInput.h"



class mqttFloatInput
{
private:
    PubSubClient *pClient;
    const char *device;
    const char *name;
    FloatInput *pFloatInput;
    void publishStatus();
    

public:
    mqttFloatInput(PubSubClient *client, const char *deviceName,const char *floatInputName, FloatInput *input);
    void loop();
    void reconnected();
    void mqttCallback(char *topic, byte *payload, unsigned int length);

};

#endif