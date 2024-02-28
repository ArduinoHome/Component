#include "mqttFloatInput.h"


mqttFloatInput::mqttFloatInput(PubSubClient *mqttPtr, const char *deviceName, const char *floatInputName, FloatInput *input) : device(deviceName), name(floatInputName)
{
    pClient = mqttPtr;
    pFloatInput = input;
}

void mqttFloatInput::loop()
{
    if (pFloatInput->HasChanged())
        publishStatus();
}

void mqttFloatInput::reconnected()
{
    if (pClient->connected())
        publishStatus();
}

void mqttFloatInput::mqttCallback(char *topic, byte *payload, unsigned int length){}

void mqttFloatInput::publishStatus()
{
    if (pClient->connected())
    {
        String t = String(device) + String(F("/floatInput/")) + String(name) + String(F("/state"));
        char topicArray[t.length() + 1];
        t.toCharArray(topicArray, sizeof(topicArray));

        String v = (String)pFloatInput->GetValue();
        char valueArray[v.length() + 1];
        v.toCharArray(valueArray, sizeof(valueArray));

        pClient->publish(topicArray, valueArray, true);
    }
}
