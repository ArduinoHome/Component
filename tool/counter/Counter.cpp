#include "Counter.h"




void Counter::Start()
{
    startTime = millis();
    enabled = true;
}



void Counter::Stop()
{
    if(enabled == true)
        offsetTime =+ millis() - startTime;
    enabled = false;
}


void Counter::Reset()
{
    offsetTime = 0;
}


bool Counter::isStopped()
{
    return !enabled;
}

unsigned long Counter::TimeElapsed()
{
    if(enabled == false)
        return offsetTime;
    else
        return (millis() - startTime) + offsetTime;
}