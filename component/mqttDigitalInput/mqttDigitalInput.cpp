#include "mqttDigitalInput.h"
#define ON "1"
#define OFF "0"

mqttDigitalInput::mqttDigitalInput(PubSubClient *mqttPtr, const char *deviceName, const char *digitalInputName, DigitalInput *input) : device(deviceName), name(digitalInputName)
{
    pClient = mqttPtr;
    pDigitalInput = input;
}

void mqttDigitalInput::loop()
{
    if (pDigitalInput->HasChanged())
        publishStatus();
}

void mqttDigitalInput::reconnected()
{
    if (pClient->connected())
        publishStatus();
}

void mqttDigitalInput::mqttCallback(char *topic, byte *payload, unsigned int length)
{
 
}

void mqttDigitalInput::publishStatus()
{
    if (pClient->connected())
    {
        String r = String(device) + String("/digitalInput/") + String(name) + String("/state");
        char charArray[r.length() + 1];
        r.toCharArray(charArray, sizeof(charArray));

        pClient->publish(charArray, pDigitalInput->GetValue() ? ON : OFF, true);
    }
}
