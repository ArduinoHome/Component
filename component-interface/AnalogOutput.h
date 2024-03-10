#ifndef ANALOGOUTPUT_H
#define ANALOGOUTPUT_H

class AnalogOutput
{
public:
    virtual int GetValue();
    virtual void SetValue(int value);
    virtual bool HasChanged();
    virtual void Increment(int incrValue = 1);
    virtual void Decrement(int decrValue = 1);
};

#endif