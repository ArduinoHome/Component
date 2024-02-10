#ifndef BOARDREBOOT_H
#define BOARDREBOOT_H

#include <PubSubClient.h>
#include <Arduino.h>


class BoardReboot
{
private:
    PubSubClient *mqttClient;
    char *topicCmd;
    void (*Reboot)(void) = 0;

public:
    BoardReboot();
    BoardReboot(PubSubClient *mqttPtr, const char *deviceName);
    void loop();
    void reconnected();
    void mqttCallback(char *topic, byte *payload, unsigned int length);
};

#endif