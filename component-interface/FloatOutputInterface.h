#ifndef FLOATOUTPUTINTERFACE_H
#define FLOATOUTPUTINTERFACE_H

class FloatOutputInterface
{
public:
    virtual double GetValue();
    virtual void SetValue(double value);
    virtual bool HasChanged();
};

#endif