#include "mqttSwitchDelayed.h"

mqttSwitchDelayed::mqttSwitchDelayed(PubSubClient *client, const char *deviceName,const DeviceClass deviceclass,const char *switchName, DigitalInputInterface *input, DigitalOutputInterface *output, const unsigned long delay, const bool isButton = true) : device(deviceName), name(switchName), SwitchDelayed(input,output,delay,isButton),mDeviceclass(deviceclass)
{
    pClient = client;
}

void mqttSwitchDelayed::loop()
{
    SwitchDelayed::loop();
    if (SwitchDelayed::HasChanged())
        publishSwitchStatus();
}

void mqttSwitchDelayed::reconnected()
{
    String topicCommand = "ArduinoHome/"+String(device) +"/"+ String(DeviceClassText[mDeviceclass]) + "/"+ String(name) + String(F("/command"));

    if (pClient->connected())
        pClient->subscribe(topicCommand.c_str());

    publishSwitchStatus();
}

void mqttSwitchDelayed::mqttCallback(char *topic, byte *payload, unsigned int length)
{
    String topicCommand = "ArduinoHome/"+String(device) +"/"+ String(DeviceClassText[mDeviceclass]) + "/"+ String(name) + String(F("/command"));

    if (strcmp(topic, topicCommand.c_str()) == 0)
    {
        if (memcmp(payload, MQTTSWITCHDELAYED_ON, length) == 0)
            SwitchDelayed::SetValue(true);
        else if (memcmp(payload, MQTTSWITCHDELAYED_OFF, length) == 0)
            SwitchDelayed::SetValue(false);
        else if (memcmp(payload, MQTTSWITCHDELAYED_TOGGLE, length) == 0)
            SwitchDelayed::Toggle();
        

        publishSwitchStatus();
    }
}

void mqttSwitchDelayed::publishSwitchStatus()
{
    if (pClient->connected())
    {
        String topic = "ArduinoHome/"+String(device) +"/"+ String(DeviceClassText[mDeviceclass]) + "/"+ String(name) + String(F("/state"));
        pClient->publish(topic.c_str(), SwitchDelayed::GetValue() ? MQTTSWITCHDELAYED_ON : MQTTSWITCHDELAYED_OFF, true);
    }
}