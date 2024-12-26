#include "mqttDigitalOutput.h"


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
    String topicCommand = "ArduinoHome/"+String(device) + String(F("/digitalOutput/")) + String(name) + String(F("/command"));
    
    if (strcmp(topic, topicCommand.c_str()) == 0)
    {
        if (memcmp(payload, MQTTDIGITALOUTPUT_ON, length) == 0)
            pDigitalOutput->SetOn();
        else if (memcmp(payload, MQTTDIGITALOUTPUT_OFF, length) == 0)
            pDigitalOutput->SetOff();
        // else if (memcmp(payload, MQTTDIGITALOUTPUT_TOGGLE, length) == 0)
        //     pDigitalOutput->Toggle();

        publishStatus();
    }
}

void mqttDigitalOutput::publishStatus()
{
    if (pClient->connected())
    {
        String topic = "ArduinoHome/"+String(device) + String(F("/digitalOutput/")) + String(name) + String(F("/state"));
        pClient->publish(topic.c_str(), pDigitalOutput->GetValue() ? MQTTDIGITALOUTPUT_ON : MQTTDIGITALOUTPUT_OFF, true);
    }
}
