#include "mqttLightDelayed.h"
#define ON "1"
#define OFF "0"

mqttLightDelayed::mqttLightDelayed(PubSubClient *client, const char *deviceName,const char *lightName, DigitalInput *input, DigitalOutput *output, const unsigned long delay, const bool isButton = true) : device(deviceName), light(lightName), LightDelayed(input,output,delay,isButton)
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
    String r = String(device) + String("/light/") + String(light) + String("/command");
    char charArray[r.length() + 1];
    r.toCharArray(charArray, sizeof(charArray));

    if (pClient->connected())
        pClient->subscribe(charArray);

    publishLightStatus();
}

void mqttLightDelayed::mqttCallback(char *topic, byte *payload, unsigned int length)
{
    String r = String(device) + String("/light/") + String(light) + String("/command");
    char charArray[r.length() + 1];
    r.toCharArray(charArray, sizeof(charArray));

    if (strcmp(topic, charArray) == 0)
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
        String r = String(device) + String("/light/") + String(light) + String("/state");
        char charArray[r.length() + 1];
        r.toCharArray(charArray, sizeof(charArray));

        pClient->publish(charArray, LightDelayed::GetValue() ? ON : OFF, true);
    }
}