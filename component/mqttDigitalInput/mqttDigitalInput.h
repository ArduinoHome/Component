#ifndef MQTTDIGITALINPUT_H
#define MQTTDIGITALINPUT_H

#include <Ethernet.h>
#include <PubSubClient.h>
#include <Arduino.h>
#include "DigitalInput.h"



class mqttDigitalInput
{
private:
    PubSubClient *pClient;
    const char *device;
    const char *name;
    DigitalInput *pDigitalInput;
    void publishStatus();
    

public:
    mqttDigitalInput(PubSubClient *client, const char *deviceName,const char *digitalInputName, DigitalInput *input);
    void loop();
    void reconnected();
    void mqttCallback(char *topic, byte *payload, unsigned int length);

};

#endif