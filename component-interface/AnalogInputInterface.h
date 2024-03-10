#ifndef ANALOGINPUTINTERFACE_H
#define ANALOGINPUTINTERFACE_H

class AnalogInputInterface
{
public:
    virtual int GetValue();
    virtual bool HasChanged();

};

#endif