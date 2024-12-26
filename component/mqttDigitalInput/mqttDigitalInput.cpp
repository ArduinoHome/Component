#include "mqttDigitalInput.h"

mqttDigitalInput::mqttDigitalInput(PubSubClient *mqttPtr, const char *deviceName, const char *digitalInputName, DigitalInputInterface *input) : device(deviceName), name(digitalInputName)
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
        String topic = "ArduinoHome/"+String(device) + String(F("/digitalInput/")) + String(name) + String(F("/state"));
        pClient->publish(topic.c_str(), pDigitalInput->GetValue() ? MQTTDIGITALINPUT_ON : MQTTDIGITALINPUT_OFF, true);
    }
}
