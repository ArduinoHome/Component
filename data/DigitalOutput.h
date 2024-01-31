#ifndef DIGITALOUTPUT_H
#define DIGITALOUTPUT_H

class DigitalOutput
{
public:
    virtual bool GetValue();
    virtual void SetValue(bool value);
    virtual void SetOn();
    virtual void SetOff();
    virtual void Toggle();
};

#endif