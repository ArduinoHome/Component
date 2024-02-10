#include "BoardReboot.h"

BoardReboot::BoardReboot() {}

BoardReboot::BoardReboot(PubSubClient *mqttPtr, const char *deviceName)
{
    this->mqttClient = mqttPtr;
    snprintf(this->topicCmd, sizeof(this->topicCmd), "%s/reboot", deviceName);
}

void BoardReboot::loop(){}

void BoardReboot::reconnected()
{
    if (mqttClient->connected())
    {
        mqttClient->subscribe(topicCmd);
    }
}

void BoardReboot::mqttCallback(char *topic, byte *payload, unsigned int length)
{
    if (strcmp(topic, topicCmd) == 0)
    {
        Reboot();
    }
}
