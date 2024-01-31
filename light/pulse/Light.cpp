#include "Light.h"
#define ON "1"
#define OFF "0"

Light::Light(){}

Light::Light(PubSubClient *mqttPtr, const char *topicCmd, const char *topicStatus, DigitalInput *input,DigitalOutput *output)
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

        if (mqttClient->connected())
            mqttClient->publish(topicStatus, output->GetValue() ? ON : OFF, true);
    }
}

void Light::reconnected()
{
    mqttClient->subscribe(topicCmd);
    if (mqttClient->connected())
        mqttClient->publish(topicStatus, output->GetValue() ? ON : OFF, true);
}

void Light::mqttCallback(char *topic, byte *payload, unsigned int length)
{
    if (strcmp(topic, topicCmd) == 0)
    {
        if (payload[0] == '1')
            output->SetOn();
        else if (payload[0] == '0')
            output->SetOff();

        if (mqttClient->connected())
            mqttClient->publish(topicStatus, output->GetValue() ? ON : OFF, true);
    }
}