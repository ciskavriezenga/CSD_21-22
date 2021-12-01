#include "saw.h"
#include "sine.h"

/*
 * Simple example of the need for virtual methods
 * We allocate a sine and square object dynamically
 */

int main()
{
  Oscillator osc;
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

  /*
   * WE NEED THE KEYWORD 'virtual'!
   *
   * _______ * * * DIY * * *  _______
   * 1. add the keyword 'virtual' to the header of the baseclass as follow:
   *  virtual void calculate();
   *
   * now rebuild: make clean, make - because you only altered a header!
   * which calculate method is called?
   *
   * 2. create an object of the type Oscillator in the main.cpp:
   * Oscillator osc;
   * (for the sake of this example there is no need to make this dynamic).
   * rebuild and rerun your code. Does it work?
   *
   * 3. Now, change the virtual method definition ('virtual void calculate()')
   * in the baseclass into:
   * virtual void calculate() = 0;
   * AND remove the implementation of this method in the oscillator.cpp file.
   * rebuild (rember to run 'make clean' first!) your code --> do you succeed?
   * ....
   * ...
   * ..
   * .
   *
   * NO ...
   * You will get the following error:
   * main.cpp:11:14: error: variable type 'Oscillator' is an abstract class
   * Oscillator osc;
   *             ^
   * ./oscillator.h:11:16: note: unimplemented pure virtual method 'calculate' in 'Oscillator'
   * virtual void calculate() = 0;
   *
   * Questions:
   * Why can't you create an instance of the type Oscillator?
   * When you view this from the perspective of categories - e.g. Pet, Cat, Dog
   * does it then 'make sense' that you can not create a Pet? But you can create
   * a Dog or Cat?
   */


  // delete dynamically allocated objects
  delete sine;
  sine = nullptr;
  delete saw;
  saw = nullptr;
}
