#include "mqttDigitalOutput.h"
#define ON "1"
#define OFF "0"

mqttDigitalOutput::mqttDigitalOutput(PubSubClient *client, const char *deviceName,const char *digitalOutputName,DigitalOutputInterface *output) : device(deviceName), name(digitalOutputName)
{
    pClient = client;
    pDigitalOutput = output;
}

void mqttDigitalOutput::loop(){}

void mqttDigitalOutput::reconnected()
{
    String topicCommand = String(device) + String(F("/digitalOutput/")) + String(name) + String(F("/command"));
    
    if (pClient->connected())
        pClient->subscribe(topicCommand.c_str());

    publishStatus();
}

void mqttDigitalOutput::mqttCallback(char *topic, byte *payload, unsigned int length)
{
    String topicCommand = String(device) + String(F("/digitalOutput/")) + String(name) + String(F("/command"));
    
    if (strcmp(topic, topicCommand.c_str()) == 0)
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
        String topic = String(device) + String(F("/digitalOutput/")) + String(name) + String(F("/state"));
        pClient->publish(topic.c_str(), pDigitalOutput->GetValue() ? ON : OFF, true);
    }
}
