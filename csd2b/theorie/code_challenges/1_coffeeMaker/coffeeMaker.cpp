#include <iostream>

// ____________________ CoffeeMaker class definition ____________________

class CoffeeMaker
{
public:
  CoffeeMaker();
  ~CoffeeMaker();

  //___ fields ___
  // type: e.g. "espresso machine", "french press", 'moka pot"
  std::string type;
  std::string brand;
   // the amount of coffee the coffeemaker needs
  float necessaryCoffeeAmount;
  // the current amount that is in the coffeeMaker
  float currentCoffeeAmount;

  //___ methods ___
  // adds the passed coffeeVolume to the field currentCoffeeAmount
  void addCoffee(float coffeeAmount);
  // check if the necessaryCoffeeAmount is reached
  bool isFilled();
  // brew coffee! and return true if brewing went successful
  bool brew();

};

// ____________________ CoffeeMaker class implementation ____________________

CoffeeMaker::CoffeeMaker() {
  std::cout << "Inside CoffeeMaker constructor\n";
  // TODO - add parameters and initilize values, some based on these parameters
}

CoffeeMaker::~CoffeeMaker() {
  std::cout << "Inside CoffeeMaker destructor\n";
}

void CoffeeMaker::addCoffee(float coffeeAmount) {
  std::cout << "Inside CoffeeMaker addCoffee\n";
  // TODO - write method body
}

bool CoffeeMaker::isFilled() {
  // TODO make sure it does not overflow by using necessaryCoffeeAmount
  std::cout << "Inside CoffeeMaker isFilled\n";
  // TODO - write method body
  return false;
}

bool CoffeeMaker::brew() {
  std::cout << "Inside CoffeeMaker brew\n";
  //TODO  add check if the currentCoffeeAmount is large enough
  //      and then maybe post the strenght of a coffee, using a switch?
  // TODO - write method body
  return false;
}


// ____________________ main ____________________
int main() {
  // create CoffeeMaker object and call all its functions
  CoffeeMaker coffeeMaker;
  coffeeMaker.addCoffee(1.1);
  coffeeMaker.isFilled();
  coffeeMaker.brew();

  // end program
  return 0;
}
