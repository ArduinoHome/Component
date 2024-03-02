#ifndef TIMER_H
#define TIMER_H
#include <Arduino.h>


class Timer
{
private:
    unsigned long startTime;
    unsigned long interval;
    bool reset;
    bool enabled =false;

public:
    Timer();
    void Start(unsigned long interval, bool reset);
    bool Elapsed();
    void Stop();
};

#endif