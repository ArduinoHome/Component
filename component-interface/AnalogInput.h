#ifndef ANALOGINPUT_H
#define ANALOGINPUT_H

class AnalogInput
{
public:
    virtual int GetValue();
    virtual bool HasChanged();

};

#endif