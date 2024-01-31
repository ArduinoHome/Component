#include "Timer.h"

Timer::Timer() {}

void Timer::Start(unsigned long interval, bool reset = false)
{
    this->interval = interval;
    this->reset = reset;
    this->startTime = millis();
}

bool Timer::Elapsed()
{
    bool result = false;

    if ((millis() - startTime) >= interval)
    {
        result = true;
        if (reset)
            startTime = millis();
    }

    return result;
}