#include "Switch.h"

Switch::Switch(DigitalInputInterface *input, DigitalOutputInterface *output, const bool isButton = true) : button(isButton)
{
    pDigitalInput = input;
    pDigitalOutput = output;
}

void Switch::loop()
{
    changed = false;
    if ((button && pDigitalInput->HasChanged() && pDigitalInput->GetValue()) || (!button && pDigitalInput->HasChanged()))
    {
        pDigitalOutput->Toggle();
        changed = true;
    }
}

bool Switch::GetValue()
{
    return pDigitalOutput->GetValue();
}

bool Switch::HasChanged()
{
    return changed;
}

void Switch::SetValue(bool newValue)
{
    if (newValue != pDigitalOutput->GetValue())
        changed = true;
    pDigitalOutput->SetValue(newValue);
}

void Switch::Toggle()
{
    changed = true;
    pDigitalOutput->Toggle();
}