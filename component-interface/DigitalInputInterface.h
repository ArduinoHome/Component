#ifndef DIGITALINPUTINTERFACE_H
#define DIGITALINPUTINTERFACE_H

class DigitalInputInterface
{
public:
    virtual bool GetValue();
    virtual bool HasChanged();
};

#endif