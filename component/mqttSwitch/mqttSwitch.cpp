#include "mqttSwitch.h"

mqttSwitch::mqttSwitch(PubSubClient *client, const char *deviceName, const DeviceClass deviceclass, const char *lightName, DigitalInputInterface *input, DigitalOutputInterface *output, const bool isButton) : device(deviceName), name(lightName), Switch(input, output, isButton),mDeviceclass(deviceclass)
{
    pClient = client;
}

void mqttSwitch::loop()
{
    Switch::loop();
    if (Switch::HasChanged())
        publishSwitchStatus();
}

void mqttSwitch::reconnected()
{
    String topicCommand = "ArduinoHome/"+String(device) +"/"+ String(DeviceClassText[mDeviceclass]) + "/"+ String(name) + String(F("/command"));

    if (pClient->connected())
        pClient->subscribe(topicCommand.c_str());

    publishSwitchStatus();
}

void mqttSwitch::mqttCallback(char *topic, byte *payload, unsigned int length)
{
    String topicCommand = "ArduinoHome/"+String(device) +"/"+ String(DeviceClassText[mDeviceclass]) + "/"+ String(name) + String(F("/command"));

    if (strcmp(topic, topicCommand.c_str()) == 0)
    {
        if (memcmp(payload, MQTTLIGHT_ON, length) == 0)
            Switch::SetValue(true);
        else if (memcmp(payload, MQTTLIGHT_OFF, length) == 0)
            Switch::SetValue(false);
        else if (memcmp(payload, MQTTLIGHT_TOGGLE, length) == 0)
            Switch::Toggle();

        publishSwitchStatus();
    }
}

void mqttSwitch::publishSwitchStatus()
{
    if (pClient->connected())
    {
        String topic = "ArduinoHome/"+String(device) +"/"+ String(DeviceClassText[mDeviceclass]) + "/"+ String(name) + String(F("/state"));
        pClient->publish(topic.c_str(), Switch::GetValue() ? MQTTLIGHT_ON : MQTTLIGHT_OFF, true);
    }
}

void mqttSwitch::toggle()
{
    Switch::Toggle();
    publishSwitchStatus();
}

void mqttSwitch::SetValue(bool newValue)
{
    Switch::SetValue(newValue);
    publishSwitchStatus();
}
