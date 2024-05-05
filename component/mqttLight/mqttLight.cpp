#include "mqttLight.h"

mqttLight::mqttLight(PubSubClient *client, const char *deviceName, const DeviceClass deviceclass, const char *lightName, DigitalInputInterface *input, DigitalOutputInterface *output, const bool isButton) : device(deviceName), name(lightName), Light(input, output, isButton),mDeviceclass(deviceclass)
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
    String topicCommand = String(device) +"/light/"+ String(name) + String(F("/command"));

    if (pClient->connected())
        pClient->subscribe(topicCommand.c_str());

    publishLightStatus();
}

void mqttLight::mqttCallback(char *topic, byte *payload, unsigned int length)
{
    String topicCommand = String(device) +"/light/"+ String(name) + String(F("/command"));

    if (strcmp(topic, topicCommand.c_str()) == 0)
    {
        if (memcmp(payload, MQTTLIGHT_ON, length) == 0)
            Light::SetValue(true);
        else if (memcmp(payload, MQTTLIGHT_OFF, length) == 0)
            Light::SetValue(false);
        else if (memcmp(payload, MQTTLIGHT_TOGGLE, length) == 0)
            Light::Toggle();

        publishLightStatus();
    }
}

void mqttLight::publishLightStatus()
{
    if (pClient->connected())
    {
        String topic = String(device) +"/light/"+ String(name) + String(F("/state"));
        pClient->publish(topic.c_str(), Light::GetValue() ? MQTTLIGHT_ON : MQTTLIGHT_OFF, true);
    }
}