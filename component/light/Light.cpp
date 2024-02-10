#include "Light.h"
#define ON "1"
#define OFF "0"

Light::Light() {}

Light::Light(PubSubClient *mqttPtr, const char *deviceName, const char *lightName, DigitalInput *input, DigitalOutput *output)
{
    this->mqttClient = mqttPtr;
    snprintf(this->topicCmd, sizeof(this->topicCmd), "%s/light/%s/cmd", deviceName, lightName);
    snprintf(this->topicStatus, sizeof(this->topicStatus), "%s/light/%s/status", deviceName, lightName);
    this->input = input;
}

void Light::loop()
{
    if (input->GetValue() && !MemState)
    {
        output->Toggle();
        publishLigtStatus();
    }
    MemState = input->GetValue();
}

void Light::reconnected()
{
    if (mqttClient->connected())
    {
        mqttClient->subscribe(topicCmd);
        publishLigtStatus();
    }
}

void Light::mqttCallback(char *topic, byte *payload, unsigned int length)
{
    if (strcmp(topic, topicCmd) == 0)
    {
        if (payload[0] == '1')
            output->SetOn();
        else if (payload[0] == '0')
            output->SetOff();

        publishLigtStatus();
    }
}

void Light::publishLigtStatus()
{
    if (mqttClient->connected())
        mqttClient->publish(topicStatus, output->GetValue() ? ON : OFF, true);
}