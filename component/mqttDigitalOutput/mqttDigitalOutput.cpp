#include "mqttDigitalOutput.h"
#define ON "1"
#define OFF "0"

mqttDigitalOutput::mqttDigitalOutput(PubSubClient *client, const char *deviceName,const char *digitalOutputName,DigitalOutput *output) : device(deviceName), name(digitalOutputName)
{
    pClient = client;
    pDigitalOutput = output;
}

void mqttDigitalOutput::loop()
{

}

void mqttDigitalOutput::reconnected()
{
    String r = String(device) + String("/digitalOutput/") + String(name) + String("/command");
    char charArray[r.length() + 1];
    r.toCharArray(charArray, sizeof(charArray));

    if (pClient->connected())
        pClient->subscribe(charArray);

    publishStatus();
}

void mqttDigitalOutput::mqttCallback(char *topic, byte *payload, unsigned int length)
{
    String r = String(device) + String("/digitalOutput/") + String(name) + String("/command");
    char charArray[r.length() + 1];
    r.toCharArray(charArray, sizeof(charArray));

    if (strcmp(topic, charArray) == 0)
    {
        if (payload[0] == '1')
            pDigitalOutput->SetOn();
        else if (payload[0] == '0')
            pDigitalOutput->SetOff();

        publishStatus();
    }
}

void mqttDigitalOutput::publishStatus()
{
    if (pClient->connected())
    {
        String r = String(device) + String("/digitalOutput/") + String(name) + String("/state");
        char charArray[r.length() + 1];
        r.toCharArray(charArray, sizeof(charArray));

        pClient->publish(charArray, pDigitalOutput->GetValue() ? ON : OFF, true);
    }
}
