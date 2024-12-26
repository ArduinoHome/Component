#ifndef MQTTSWITCHDELAYED_H
#define MQTTSWITCHDELAYED_H

#include <PubSubClient.h>
#include "SwitchDelayed.h"
#include "mqttSwitchDelayedParam.h"
#include "DeviceClassDataInterface.h"

class mqttSwitchDelayed : public SwitchDelayed
{
private:
    PubSubClient *pClient;
    const char *device;
    const char *name;
    void publishSwitchStatus();
    const DeviceClass mDeviceclass;

public:
    mqttSwitchDelayed(PubSubClient *client, const char *deviceName,const DeviceClass deviceclass,const char *switchName, DigitalInputInterface *input, DigitalOutputInterface *output, const unsigned long delay, const bool isButton = true);
    void loop();
    void reconnected();
    void mqttCallback(char *topic, byte *payload, unsigned int length);
};

#endif