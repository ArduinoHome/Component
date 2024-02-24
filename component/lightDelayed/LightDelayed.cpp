#include "LightDelayed.h"
#define ON "1"
#define OFF "0"

LightDelayed::LightDelayed(PubSubClient *client, const char *deviceName, const char *lightName, DigitalInput *input, DigitalOutput *output, const unsigned long delay) : device(deviceName), light(lightName), lightDelay(delay)
{
    pClient = client;
    pDigitalInput = input;
    pDigitalOutput = output;
}

void LightDelayed::loop()
{
    if (pDigitalInput->HasChanged() && pDigitalInput->GetValue())
    {
        pDigitalOutput->SetOn();
        publishLightStatus();
        timer.Start(lightDelay, false);
    }

    if (timer.Elapsed())
    {
        pDigitalOutput->SetOff();
        publishLightStatus();
    }
}

void LightDelayed::reconnected()
{
    String r = String(device) + String("/light/") + String(light) + String("/command");
    char charArray[r.length() + 1];
    r.toCharArray(charArray, sizeof(charArray));

    if (pClient->connected())
        pClient->subscribe(charArray);

    publishLightStatus();
}

void LightDelayed::mqttCallback(char *topic, byte *payload, unsigned int length)
{
    String r = String(device) + String("/light/") + String(light) + String("/command");
    char charArray[r.length() + 1];
    r.toCharArray(charArray, sizeof(charArray));

    if (strcmp(topic, charArray) == 0)
    {
        if (payload[0] == '1')
        {
            timer.Start(lightDelay, false);
            pDigitalOutput->SetOn();
        }
        else if (payload[0] == '0')
            pDigitalOutput->SetOff();
        else if (payload[0] == 't')
        {
            if (pDigitalOutput->GetValue())
                timer.Start(lightDelay, false);
            pDigitalOutput->Toggle();
        }

        publishLightStatus();
    }
}

void LightDelayed::publishLightStatus()
{
    if (pClient->connected())
    {
        String r = String(device) + String("/light/") + String(light) + String("/state");
        char charArray[r.length() + 1];
        r.toCharArray(charArray, sizeof(charArray));

        pClient->publish(charArray, pDigitalOutput->GetValue() ? ON : OFF, true);
    }
}