#ifndef COVERINTERFACE_H
#define COVERINTERFACE_H
#include <Arduino.h>
#include "LockDataInterface.h"


class LockInterface
{
public:
    virtual LockState GetValue();
    virtual bool HasChanged();
    virtual void SetValue(LockCommand newValue);
    virtual void Toggle();
};

#endif