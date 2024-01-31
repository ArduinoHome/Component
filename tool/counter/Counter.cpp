


// unsigned long counter(bool input, unsigned long *tmp, bool *memval)
// {
//   unsigned long result = 0;
//   if (input == true && *memval == false)
//     *tmp = millis();

//   // if (input == false && *memval == true)
//   result = millis() - *tmp;

//   *memval = input;

//   return result;
// }