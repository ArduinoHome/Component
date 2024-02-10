#ifndef LIGHT_H
#define LIGHT_H

#include <Ethernet.h>
#include <PubSubClient.h>
#include <Arduino.h>
#include <BoardDigitalInput.h>
#include <BoardDigitalOutput.h>

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
    Light(PubSubClient *mqttPtr, const char *lightName, const char *deviceName, DigitalInput *input,DigitalOutput *output);
    void loop();
    void reconnected();
    void mqttCallback(char *topic, byte *payload, unsigned int length);
};

#endif