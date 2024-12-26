#include "SwitchDelayed.h"

SwitchDelayed::SwitchDelayed(DigitalInputInterface *input, DigitalOutputInterface *output, const unsigned long delay, const bool isButton = true) : switchDelay(delay), Switch(input, output, isButton)
{
}

void SwitchDelayed::loop()
{
    Switch::loop();
    if (Switch::GetValue())
    {
        if (Switch::HasChanged())
            timer.Start(switchDelay, false);

        if (timer.Elapsed())
            Switch::SetValue(false);
    }
}

void SwitchDelayed::SetValue(bool newValue)
{
    if (Switch::GetValue() != newValue && newValue)
        timer.Start(switchDelay, false);
    Switch::SetValue(newValue);
}

void SwitchDelayed::Toggle()
{
    Switch::Toggle();
    timer.Start(switchDelay, false);
}
