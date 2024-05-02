#include "mqttAnalogInput.h"


mqttAnalogInput::mqttAnalogInput(PubSubClient *mqttPtr, const char *deviceName, const char *analogInputName, AnalogInputInterface *input,const unsigned long scaninterval) : device(deviceName), name(analogInputName)
{
    pClient = mqttPtr;
    pAnalogInput = input;
    scan.Start(scaninterval,true);
}

void mqttAnalogInput::loop()
{
    if(scan.Elapsed())
        publishStatus();
}

void mqttAnalogInput::reconnected()
{
    if (pClient->connected())
        publishStatus();
}

void mqttAnalogInput::mqttCallback(char *topic, byte *payload, unsigned int length){}

void mqttAnalogInput::publishStatus()
{
    if (pClient->connected())
    {
        String topic = String(device) + "/analogInput/" + name + "/state";
        String value = String(pAnalogInput->GetValue());

        pClient->publish(topic.c_str(), value.c_str(), true);
    }
}
