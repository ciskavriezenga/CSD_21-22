#include "saw.h"
#include "sine.h"

/*
 * Simple example of the need for virtual methods
 * We allocate a sine and square object dynamically
 */

int main()
{
  /*
   * Create the sine and saw objects dynamically with the keyword 'new'
   * This returns a pointer to the sine object, which we can store in
   * a class pointer, e.g. a Sine pointer or a Saw pointer
   * a pointer type is indicated with a *, which is simply a convention.
   */
  Sine* sine = new Sine();
  Saw* saw = new Saw();

  /*
   * because the base class calculate methods are overridden in the subclass,
   * the calculate function of the subclass is called, not the baseclass.
   */
  sine->calculate();
  saw->calculate();


  /*
   * Now let's store the pointers to the sine and saw objects in a Oscillator
   * pointer!
   */
  Oscillator* sineOscillator = sine;
  Oscillator* sawOscillator = saw;

  /*
   * OOF....! - when we call the calculate method of the sine object with an
   * oscillator pointer ... it will go 'terribly wrong'
   * the calculate function of the baseclas is called, not the subclass method.
   */
  sineOscillator->calculate();
  sawOscillator->calculate();

  /*
   * WE NEED THE KEYWORD 'virtual'!
   *
   * _______ * * * DIY * * *  _______
   * • add the keyword 'virtual' to the header of the baseclass as follow:
   *  virtual void calculate();
   *
   * now rebuild: make clean, make - because you only altered a header!
   * which calculate method is called?
   *
   */


  // delete dynamically allocated objects
  delete sine;
  sine = nullptr;
  delete saw;
  saw = nullptr;
}
