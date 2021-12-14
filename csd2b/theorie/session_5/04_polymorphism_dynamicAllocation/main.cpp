#include "saw.h"
#include "sine.h"

/*
 * Simple example of the need for virtual methods
 * We allocate a sine and square object dynamically
 */

int main()
{
#if 1 // build example 1

  /*
   * Create the sine and saw objects dynamically with the keyword 'new'
   * This returns a pointer to the sine object, which we can store in
   * a 'class pointer', e.g. a Sine pointer or a Saw pointer
   * a pointer type is indicated with a *, which is simply a convention.
   */
  Sine* sine = new Sine();
  Saw* saw = new Saw();

  /*
   * because the base class calculate method is overridden in both subclasses,
   * the calculate method of the subclass is called, instead of the calculate
   * method of the baseclass.
   */
  sine->calculate();
  saw->calculate();

  /*
   * Now let's store the pointers to the sine and saw objects in an Oscillator
   * pointer!
   */
  Oscillator* sineOscillator = sine;
  Oscillator* sawOscillator = saw;

  /*
   * OOF....! - when we call the calculate method of the sine object with an
   * oscillator pointer ... it will go 'terribly wrong'
   * the calculate function of the baseclass is called, not the subclass method.
   */
  sineOscillator->calculate();
  sawOscillator->calculate();

  // delete dynamically allocated objects
  delete sine;
  sine = nullptr;
  delete saw;
  saw = nullptr;


#else //build example 2

  Oscillator* osc = nullptr;
  int choice = 0;
  if(choice == 0) {
    osc = new Sine();
  } else {
    osc = new Saw();
  }

  osc->calculate();
  // delete dynamically allocated objects
  delete osc;
  osc = nullptr;
#endif
}
