#include "Timer.h"

Timer::Timer() {}

void Timer::Start(unsigned long interval, bool reset = false)
{
    this->interval = interval;
    this->reset = reset;
    this->startTime = millis();
    enabled = true;
}

void Timer::Stop()
{
    enabled = false;
}

bool Timer::Elapsed()
{
    bool result = false;

    if ((millis() - startTime) >= interval && enabled == true)
    {
        result = true;
        if (reset)
            startTime = millis();
        else
            enabled = false;
    }

    return result;
}