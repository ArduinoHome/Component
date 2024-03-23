#ifndef BOARDMQTTDIGITALINPUT_H
#define BOARDMQTTDIGITALINPUT_H

#include <PubSubClient.h>
#include <Arduino.h>
#include "DigitalInputInterface.h"

class BoardMqttDigitalInput : public DigitalInputInterface
{
private:
    PubSubClient *pClient;
    const char *device;
    const char *name;
    bool value;
    bool changed;
    byte mem;
    const bool pRevert = false;

public:
    BoardMqttDigitalInput(PubSubClient *client, const char *deviceName, const char *digitalInputName,bool initialValue = false, const bool revert = false);
    void loop();
    void reconnected();
    void mqttCallback(char *topic, byte *payload, unsigned int length);
    //void setup();
    bool GetValue();
    bool HasChanged();
};

#endif