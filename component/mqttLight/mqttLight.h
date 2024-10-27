#ifndef MQTTLIGHT_H
#define MQTTLIGHT_H

#include <PubSubClient.h>
#include "Light.h"
#include "mqttLightParam.h"
#include "DeviceClassDataInterface.h"

class mqttLight : public Light
{
private:
    PubSubClient *pClient;
    const char *device;
    const char *name;
    void publishLightStatus();
    const DeviceClass mDeviceclass;

public:
    mqttLight(PubSubClient *client, const char *deviceName,const DeviceClass deviceclass,const char *lightName, DigitalInputInterface *input, DigitalOutputInterface *output, const bool isButton = true);
    void loop();
    void reconnected();
    void mqttCallback(char *topic, byte *payload, unsigned int length);
    void SetValue(bool newValue);
    void toggle();
};

#endif