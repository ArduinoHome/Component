#ifndef DIGITALINPUT_H
#define DIGITALINPUT_H

class DigitalInput
{
public:
    virtual bool GetValue();
    virtual bool HasChanged();
};

#endif