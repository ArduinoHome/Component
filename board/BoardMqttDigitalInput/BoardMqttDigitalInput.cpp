#include "BoardMqttDigitalInput.h"
#define ON "1"
#define OFF "0"

BoardMqttDigitalInput::BoardMqttDigitalInput(PubSubClient *mqttPtr, const char *deviceName, const char *digitalInputName, bool initialValue = false, const bool revert = false) : pRevert(revert), device(deviceName), name(digitalInputName)
{
    pClient = mqttPtr;
    value = initialValue;
    mem = initialValue;
}

void BoardMqttDigitalInput::loop()
{
    changed = false;
    if (mem != value)
    {
        changed = true;
        if (mem == 3)
            mem = value = 1;
        else if (mem == 2)
            mem = value = 0;
    }
}

void BoardMqttDigitalInput::reconnected()
{
    String r = String(device) + String(F("/digitalInput/")) + String(name) + String(F("/state"));
    char charArray[r.length() + 1];
    r.toCharArray(charArray, sizeof(charArray));
    if (pClient->connected())
        pClient->subscribe(charArray);
}

void BoardMqttDigitalInput::mqttCallback(char *topic, byte *payload, unsigned int length)
{
    String r = String(device) + String(F("/digitalInput/")) + String(name) + String(F("/state"));
    char charArray[r.length() + 1];
    r.toCharArray(charArray, sizeof(charArray));

    if (strcmp(topic, charArray) == 0)
    {
        if (payload[0] == '1' && value != true)
            mem = 3;
        else if (payload[0] == '0' && value != false)
            mem = 2;
    }
}

bool BoardMqttDigitalInput::GetValue()
{
    if (!pRevert)
        return value;
    else
        return !value;
}

bool BoardMqttDigitalInput::HasChanged()
{
    return changed;
}