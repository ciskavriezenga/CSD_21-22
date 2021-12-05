#include "saw.h"
#include "sine.h"

/*
 * Simple example of the need for virtual methods
 * We allocate a sine and square object dynamically
 */

int main()
{
  /*
   * Create the sine and saw objects
   */
  Sine sine;
  Saw saw;

  /*
   * because the base class calculate method is overridden in both subclasses,
   * the calculate method of the subclass is called, instead of the calculate
   * method of the baseclass.
   */
  sine.calculate();
  saw.calculate();


  /*
   * Now let's store the address of the sine object in an Oscillator pointer!
   * Oscillator* --> Oscillator pointer
   * &sine --> with & you retrieve the address of an object
   * both the usage of the * and & symbols are simply convention
   */
  Oscillator* osc = &sine;
  osc->calculate();
  /*
   * We can also store the address of the saw in the same oscillator pointer
   */
  osc = &saw;
  osc->calculate();

}
