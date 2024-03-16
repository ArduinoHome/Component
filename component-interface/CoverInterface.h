#ifndef COVERINTERFACE_H
#define COVERINTERFACE_H
#include "CoverDataInterface.h"
#include <Arduino.h>

class CoverInterface
{
public:
    virtual CoverState GetValue();
    virtual bool HasChanged();
    virtual void SetValue(CoverCommand newValue);
    virtual byte GetPosition();
};

#endif