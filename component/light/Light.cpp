#include "Light.h"
#define ON "1"
#define OFF "0"

Light::Light(PubSubClient *mqttPtr, const char *deviceName, const char *lightName, DigitalInput *input, DigitalOutput *output) : device(deviceName), light(lightName)
{
    pClient = mqttPtr;
    pDigitalInput = input;
    pDigitalOutput = output;
}

void Light::loop()
{
    if (pDigitalInput->HasChanged() && pDigitalInput->GetValue())
    {
        pDigitalOutput->Toggle();
        publishLightStatus();
    }
}

void Light::reconnected()
{
    String r = String(device) + String("/light/") + String(light) + String("/command");
    char charArray[r.length() + 1];
    r.toCharArray(charArray, sizeof(charArray));

    if (pClient->connected())
        pClient->subscribe(charArray);

    publishLightStatus();
}

void Light::mqttCallback(char *topic, byte *payload, unsigned int length)
{
    String r = String(device) + String("/light/") + String(light) + String("/command");
    char charArray[r.length() + 1];
    r.toCharArray(charArray, sizeof(charArray));

    if (strcmp(topic, charArray) == 0)
    {
        if (payload[0] == '1')
            pDigitalOutput->SetOn();
        else if (payload[0] == '0')
            pDigitalOutput->SetOff();

        publishLightStatus();
    }
}

void Light::publishLightStatus()
{
    if (pClient->connected())
    {
        String r = String(device) + String("/light/") + String(light) + String("/state");
        char charArray[r.length() + 1];
        r.toCharArray(charArray, sizeof(charArray));

        pClient->publish(charArray, pDigitalOutput->GetValue() ? ON : OFF, true);
    }
}
