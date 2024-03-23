#include "LightDelayed.h"

LightDelayed::LightDelayed(DigitalInputInterface *input, DigitalOutputInterface *output, const unsigned long delay, const bool isButton = true) : lightDelay(delay), Light(input, output, isButton)
{
}

void LightDelayed::loop()
{
    Light::loop();
    if (Light::GetValue())
    {
        if (Light::HasChanged())
            timer.Start(lightDelay, false);

        if (timer.Elapsed())
            Light::SetValue(false);
    }
}

void LightDelayed::SetValue(bool newValue)
{
    if (Light::GetValue() != newValue && newValue)
        timer.Start(lightDelay, false);
    Light::SetValue(newValue);
}

void LightDelayed::Toggle()
{
    Light::Toggle();
    timer.Start(lightDelay, false);
}
