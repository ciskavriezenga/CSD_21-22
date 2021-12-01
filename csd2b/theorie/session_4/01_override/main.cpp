#include "saw.h"
#include "sine.h"

/*
 * Simple example of overriding methods.
 */

int main()
{
  Sine sine;
  Saw saw;

  /*
   * because the base class calculate methods are overridden in the subclass,
   * the calculate function of the subclass is called, not the baseclass.
   */
  sine.calculate();
  saw.calculate();
}
