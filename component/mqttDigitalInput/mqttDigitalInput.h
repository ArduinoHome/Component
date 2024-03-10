#ifndef MQTTDIGITALINPUT_H
#define MQTTDIGITALINPUT_H

#include <PubSubClient.h>
#include <Arduino.h>
#include "DigitalInputInterface.h"



class mqttDigitalInput
{
private:
    PubSubClient *pClient;
    const char *device;
    const char *name;
    DigitalInputInterface *pDigitalInput;
    void publishStatus();
    

public:
    mqttDigitalInput(PubSubClient *client, const char *deviceName,const char *digitalInputName, DigitalInputInterface *input);
    void loop();
    void reconnected();
    void mqttCallback(char *topic, byte *payload, unsigned int length);

};

#endif