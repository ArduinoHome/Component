#include "mqttFloatInput.h"

mqttFloatInput::mqttFloatInput(PubSubClient *mqttPtr, const char *deviceName, const char *floatInputName, FloatInputInterface *input) : device(deviceName), name(floatInputName)
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

void mqttFloatInput::mqttCallback(char *topic, byte *payload, unsigned int length) {}

void mqttFloatInput::publishStatus()
{
    if (pClient->connected())
    {
        String topic = "ArduinoHome/"+String(device) + "/floatInput/" + name + "/state";
        String value = (String)pFloatInput->GetValue();

        pClient->publish(topic.c_str(), value.c_str(), true);
    }
}
