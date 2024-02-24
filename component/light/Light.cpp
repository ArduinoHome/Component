#include "Light.h"

Light::Light(DigitalInput *input, DigitalOutput *output, const bool isButton = true) : button(isButton)
{
    pDigitalInput = input;
    pDigitalOutput = output;
}

void Light::loop()
{
    changed = false;
    if ((button && pDigitalInput->HasChanged() && pDigitalInput->GetValue()) || (!button && pDigitalInput->HasChanged()))
    {
        pDigitalOutput->Toggle();
        changed = true;
    }
}

bool Light::GetValue()
{
    return pDigitalOutput->GetValue();
}

bool Light::HasChanged()
{
    return changed;
}

void Light::SetValue(bool newValue)
{
    if (newValue != pDigitalOutput->GetValue())
        changed = true;
    pDigitalOutput->SetValue(newValue);
}

void Light::Toggle()
{
    changed = true;
    pDigitalOutput->Toggle();
}