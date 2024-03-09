#include "switchoffDelay.h"

switchoffDelay::switchoffDelay(DigitalOutput *output, const unsigned long delay) : pDelay(delay),pOutput(output)
{
}

void switchoffDelay::loop()
{
    if (pOutput->GetValue())
    {
        if (pOutput->HasChanged())
            timer.Start(pDelay, false);

        if (timer.Elapsed())
            pOutput->SetValue(false);
    }
}

void switchoffDelay::SetValue(bool newValue)
{
    if (pOutput->GetValue() != newValue && newValue)
        timer.Start(pDelay, false);
    pOutput->SetValue(newValue);
}

void switchoffDelay::Toggle()
{
    pOutput->Toggle();
    timer.Start(pDelay, false);
}

bool switchoffDelay::GetValue()
{
    return pOutput->GetValue();
}
