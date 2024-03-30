#include "switchoffDelay.h"

switchoffDelay::switchoffDelay(DigitalOutputInterface *output, const unsigned long delay) : pDelay(delay), pOutput(output)
{
}

void switchoffDelay::loop()
{
    if (pOutput->GetValue())
    {
        if (pOutput->HasChanged())
            timer.Start(pDelay, false);

        if (timer.Elapsed())
        {
            intervened = true;
            pOutput->SetValue(false);
        }
    }
}

void switchoffDelay::SetValue(bool newValue)
{
    if (pOutput->GetValue() != newValue && newValue)
    {
        intervened = false;
        timer.Start(pDelay, false);
    }
    else if (pOutput->GetValue() != newValue && !newValue)
        timer.Stop();
    pOutput->SetValue(newValue);
}

void switchoffDelay::Toggle()
{
    pOutput->Toggle();
    if (pOutput->GetValue())
        timer.Start(pDelay, false);
    else
        timer.Stop();
}

bool switchoffDelay::GetValue()
{
    return pOutput->GetValue();
}

bool switchoffDelay::Intervened()
{
    return intervened;
}