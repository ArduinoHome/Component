#include "LightDelayed.h"
#define ON "1"
#define OFF "0"

LightDelayed::LightDelayed() {}

LightDelayed::LightDelayed(PubSubClient *mqttPtr, const char *deviceName, const char *lightName, DigitalInput *input, DigitalOutput *output, unsigned long delay)
{
    this->delay = delay;
    this->mqttClient = mqttPtr;
    snprintf(this->topicCmd, sizeof(this->topicCmd), "%s/light/%s/cmd", deviceName, lightName);
    snprintf(this->topicStatus, sizeof(this->topicStatus), "%s/light/%s/status", deviceName, lightName);
    this->input = input;
}

void LightDelayed::loop()
{
    if (input->GetValue() && !MemState)
    {
        output->SetOn();
        publishLigtStatus();
        timer.Start(delay, true);
    }
    MemState = input->GetValue();

    if (timer.Elapsed())
        output->SetOff();
    
}

void LightDelayed::reconnected()
{
    if (mqttClient->connected())
    {
        mqttClient->subscribe(topicCmd);
        publishLigtStatus();
    }
}

void LightDelayed::mqttCallback(char *topic, byte *payload, unsigned int length)
{
    if (strcmp(topic, topicCmd) == 0)
    {
        if (payload[0] == '1')
        {
            timer.Start(delay, true);
            output->SetOn();
        }
        else if (payload[0] == '0')
            output->SetOff();

        publishLigtStatus();
    }
}

void LightDelayed::publishLigtStatus()
{
    if (mqttClient->connected())
        mqttClient->publish(topicStatus, output->GetValue() ? ON : OFF, true);
}