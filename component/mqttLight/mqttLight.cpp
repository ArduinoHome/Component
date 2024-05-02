#include "mqttLight.h"
#define ON "1"
#define OFF "0"

mqttLight::mqttLight(PubSubClient *client, const char *deviceName, const char *lightName, DigitalInputInterface *input, DigitalOutputInterface *output, const bool isButton) : device(deviceName), name(lightName), Light(input, output, isButton)
{
    pClient = client;
}

void mqttLight::loop()
{
    Light::loop();
    if (Light::HasChanged())
        publishLightStatus();
}

void mqttLight::reconnected()
{
    String topicCommand = String(device) + String(F("/light/")) + String(name) + String(F("/command"));
    

    if (pClient->connected())
        pClient->subscribe(topicCommand.c_str());

    publishLightStatus();
}

void mqttLight::mqttCallback(char *topic, byte *payload, unsigned int length)
{
    String topicCommand = String(device) + String(F("/light/")) + String(name) + String(F("/command"));
    

    if (strcmp(topic, topicCommand.c_str()) == 0)
    {
        if (payload[0] == '1')
            Light::SetValue(true);
        else if (payload[0] == '0')
            Light::SetValue(false);
        else if (payload[0] == 't')
            Light::Toggle();

        publishLightStatus();
    }
}

void mqttLight::publishLightStatus()
{
    if (pClient->connected())
    {
        String topic = String(device) + String(F("/light/")) + String(name) + String(F("/state"));
        pClient->publish(topic.c_str(), Light::GetValue() ? ON : OFF, true);
    }
}