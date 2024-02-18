#ifndef BOARDREBOOT_H
#define BOARDREBOOT_H

#include <PubSubClient.h>
#include <Arduino.h>


class BoardReboot
{
private:
    PubSubClient *mqttClient;
    const char *device;
    void (*Reboot)(void) = 0;

public:
    BoardReboot(PubSubClient *mqttPtr, const char *deviceName);
    void loop();
    void reconnected();
    void mqttCallback(char *topic, byte *payload, unsigned int length);
};

#endif