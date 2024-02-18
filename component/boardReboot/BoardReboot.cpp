#include "BoardReboot.h"


BoardReboot::BoardReboot(PubSubClient *mqttPtr, const char *deviceName) : device(deviceName)
{
    this->mqttClient = mqttPtr;

    // snprintf(this->topicCmd, sizeof("/reboot") + sizeof(deviceName) , "%s/reboot", deviceName);
}

void BoardReboot::loop() {}

void BoardReboot::reconnected()
{
    if (mqttClient->connected())
    {
        String r = String(device) + String("/reboot");
        char charArray[r.length() + 1];
        r.toCharArray(charArray, sizeof(charArray));
        mqttClient->subscribe(charArray);
    }
}

void BoardReboot::mqttCallback(char *topic, byte *payload, unsigned int length)
{
    String r = String(device) + String("/reboot");
    char charArray[r.length() + 1];
    r.toCharArray(charArray, sizeof(charArray));
    if (strcmp(topic, charArray) == 0)
    {
        Reboot();
    }
}
