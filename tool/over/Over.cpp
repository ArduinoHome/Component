#include "Over.h"

Over::Over(){}


bool Over::getOver(int point, int value, int distance, bool positive = true)
{
  if (positive)
  {
    if (value <= (point + distance) && value >= point)
      return true;
    else
      return false;
  }
  else
  {
    if (value >= (point - distance) && value <= point)
      return true;
    else
      return false;
  }
}