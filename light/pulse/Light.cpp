#include "Light.h"
#define ON "1"
#define OFF "0"

Light::Light() {}

Light::Light(PubSubClient *mqttPtr, const char *topicCmd, const char *topicStatus, DigitalInput *input, DigitalOutput *output)
{
    this->mqttClient = mqttPtr;
    this->topicCmd = topicCmd;
    this->topicStatus = topicStatus;
    this->input = input;
}

void Light::loop()
{
    if (input->GetValue() && !MemState)
    {
        output->Toggle();

        publishLigtStatus();
    }
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