#include "Range.h"

Range::Range() {}

bool Range::getRange(int point, int value, int radius)
{
    if ((value <= (point + radius)) && (value >= (point - radius)))
        return true;
    else
        return false;
}