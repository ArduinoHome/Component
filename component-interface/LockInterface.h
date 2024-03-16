#ifndef COVERINTERFACE_H
#define COVERINTERFACE_H
#include "LockDataInterface.h"
#include <Arduino.h>

class LockInterface
{
public:
    virtual LockState GetValue();
    virtual bool HasChanged();
    virtual void SetValue(LockCommand newValue);
    virtual byte GetPosition();
};

#endif