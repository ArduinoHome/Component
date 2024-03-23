#ifndef DIGITALOUTPUTINTERFACE_H
#define DIGITALOUTPUTINTERFACE_H

class DigitalOutputInterface
{
public:
    virtual bool GetValue();
    virtual void SetValue(bool value);
    virtual void SetOn();
    virtual void SetOff();
    virtual void Toggle();
    virtual bool HasChanged();
};

#endif