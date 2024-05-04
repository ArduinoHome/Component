#include "mqttLightDelayed.h"

mqttLightDelayed::mqttLightDelayed(PubSubClient *client, const char *deviceName,const char *lightName, DigitalInputInterface *input, DigitalOutputInterface *output, const unsigned long delay, const bool isButton = true) : device(deviceName), light(lightName), LightDelayed(input,output,delay,isButton)
{
    pClient = client;
}

void mqttLightDelayed::loop()
{
    LightDelayed::loop();
    if (LightDelayed::HasChanged())
        publishLightStatus();
}

void mqttLightDelayed::reconnected()
{
    String topicCommand = String(device) + String(F("/light/")) + String(light) + String(F("/command"));

    if (pClient->connected())
        pClient->subscribe(topicCommand.c_str());

    publishLightStatus();
}

void mqttLightDelayed::mqttCallback(char *topic, byte *payload, unsigned int length)
{
    String topicCommand = String(device) + String(F("/light/")) + String(light) + String(F("/command"));

    if (strcmp(topic, topicCommand.c_str()) == 0)
    {
        if (payload[0] == '1')
            LightDelayed::SetValue(true);
        else if (payload[0] == '0')
            LightDelayed::SetValue(false);
        else if (payload[0] == 't')
            LightDelayed::Toggle();
        

        publishLightStatus();
    }
}

void mqttLightDelayed::publishLightStatus()
{
    if (pClient->connected())
    {
        String topic = String(device) + String(F("/light/")) + String(light) + String(F("/state"));
        pClient->publish(topic.c_str(), LightDelayed::GetValue() ? ON : OFF, true);
    }
}