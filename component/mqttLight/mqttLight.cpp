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
    String r = String(device) + String(F("/light/")) + String(name) + String(F("/command"));
    char charArray[r.length() + 1];
    r.toCharArray(charArray, sizeof(charArray));

    if (pClient->connected())
        pClient->subscribe(charArray);

    publishLightStatus();
}

void mqttLight::mqttCallback(char *topic, byte *payload, unsigned int length)
{
    String r = String(device) + String(F("/light/")) + String(name) + String(F("/command"));
    char charArray[r.length() + 1];
    r.toCharArray(charArray, sizeof(charArray));

    if (strcmp(topic, charArray) == 0)
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
        String r = String(device) + String(F("/light/")) + String(name) + String(F("/state"));
        char charArray[r.length() + 1];
        r.toCharArray(charArray, sizeof(charArray));

        pClient->publish(charArray, Light::GetValue() ? ON : OFF, true);
    }
}