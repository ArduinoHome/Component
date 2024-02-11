#ifndef LIGHTDELAYED_H
#define LIGHTDELAYED_H

#include <PubSubClient.h>
#include <Arduino.h>
#include "BoardDigitalInput.h"
#include "BoardDigitalOutput.h"
#include "Timer.h"

class LightDelayed
{
private:
    unsigned long delay;
    bool MemState;
    PubSubClient *mqttClient;
    const char *topicCmd;
    const char *topicStatus;
    DigitalInput *input;
    DigitalOutput *output;
    Timer timer;
    void publishLigtStatus();

public:
    LightDelayed();
    LightDelayed(PubSubClient *mqttPtr, const char *lightName, const char *deviceName, DigitalInput *input, DigitalOutput *output, unsigned long delay);
    void loop();
    void reconnected();
    void mqttCallback(char *topic, byte *payload, unsigned int length);
};

#endif