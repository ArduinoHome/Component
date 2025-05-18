#ifndef COUNTER_H
#define COUNTER_H
#include <Arduino.h>

class Counter
{
private:
    unsigned long startTime;
    bool enabled = false;
    unsigned long offsetTime = 0;

public:
    /// @brief Reset the counter
    /// @details Reset the counter to 0. This will not stop the counter if it is running.
    /// @note This function does not reset the offset time.
    void Reset();

    /// @brief Start the counter
    /// @details 
    /// @note 
    void Start();
    
    /// @brief Stop the counter
    /// @details 
    /// @note 
    void Stop();

    /// @brief Return if the counter is stopped
    /// @details 
    /// @note 
    bool isStopped();

    /// @brief Return the elapsed time
    /// @details 
    /// @note 
    unsigned long TimeElapsed();
};

#endif