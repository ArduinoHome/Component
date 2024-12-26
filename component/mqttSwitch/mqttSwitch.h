#ifndef MQTTSWITCH_H
#define MQTTSWITCH_H

#include <PubSubClient.h>
#include "Switch.h"
#include "mqttSwitchParam.h"
#include "DeviceClassDataInterface.h"

class mqttSwitch : public Switch
{
private:
    PubSubClient *pClient;
    const char *device;
    const char *name;
    void publishSwitchStatus();
    const DeviceClass mDeviceclass;

public:
    mqttSwitch(PubSubClient *client, const char *deviceName,const DeviceClass deviceclass,const char *lightName, DigitalInputInterface *input, DigitalOutputInterface *output, const bool isButton = true);
    void loop();
    void reconnected();
    void mqttCallback(char *topic, byte *payload, unsigned int length);
    void SetValue(bool newValue);
    void toggle();
};

#endif