#ifndef FLOATINPUTINTERFACE_H
#define FLOATINPUTINTERFACE_H

class FloatInputInterface
{
public:
    virtual double GetValue();
    virtual bool HasChanged();

};

#endif