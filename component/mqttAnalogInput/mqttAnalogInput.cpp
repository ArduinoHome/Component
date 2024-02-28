#include "mqttAnalogInput.h"


mqttAnalogInput::mqttAnalogInput(PubSubClient *mqttPtr, const char *deviceName, const char *analogInputName, AnalogInput *input,const unsigned long scaninterval) : device(deviceName), name(analogInputName)
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
        String t = String(device) + String(F("/analogInput/")) + String(name) + String(F("/state"));
        char topicArray[t.length() + 1];
        t.toCharArray(topicArray, sizeof(topicArray));

        String v = (String)pAnalogInput->GetValue();
        char valueArray[v.length() + 1];
        v.toCharArray(valueArray, sizeof(valueArray));

        pClient->publish(topicArray, valueArray, true);
    }
}
