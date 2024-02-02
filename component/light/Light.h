#ifndef LIGHT_H
#define LIGHT_H

#include <Ethernet.h>
#include <PubSubClient.h>
#include <Arduino.h>
#include "DigitalInput.h"
#include "DigitalOutput.h"

class Light
{
private:
    bool MemState;
    PubSubClient *mqttClient;
    const char *topicCmd;
    const char *topicStatus;
    DigitalInput *input;
    DigitalOutput *output;
    void publishLigtStatus();

public:
    Light();
    Light(PubSubClient *mqttPtr, const char *topicCmd, const char *topicStatus,DigitalInput *input,DigitalOutput *output);
    void loop();
    void reconnected();
    void mqttCallback(char *topic, byte *payload, unsigned int length);
};

#endif