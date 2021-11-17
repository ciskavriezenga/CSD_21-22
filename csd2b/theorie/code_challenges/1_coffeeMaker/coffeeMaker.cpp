#include <iostream>

// ____________________ CoffeeMaker class definition ____________________

class CoffeeMaker
{
public:
  CoffeeMaker(std::string type, std::string brand, float necessaryCoffeeAmount);
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

CoffeeMaker::CoffeeMaker(std::string type, std::string brand, float necessaryCoffeeAmount) {
  std::cout << "• Inside CoffeeMaker constructor\n";
  // Explenation "the this pointer"
  // we need the this-pointer, to indicate which type and brand is which:
  // the parameter type and brand or the fields type and brand
  // by using the this pointer (this->) we refer to the fields of the class.
  this->type = type;
  this->brand = brand;
  this->necessaryCoffeeAmount = necessaryCoffeeAmount;
  currentCoffeeAmount = 0;

}

CoffeeMaker::~CoffeeMaker() {
  std::cout << "• Inside CoffeeMaker destructor\n";
}

void CoffeeMaker::addCoffee(float coffeeAmount) {
  // TODO make sure it does not overflow by using necessaryCoffeeAmount
  std::cout << "• Inside CoffeeMaker addCoffee\n";
  if (currentCoffeeAmount + coffeeAmount < necessaryCoffeeAmount) {
    currentCoffeeAmount += coffeeAmount;
    std::cout << "We added some coffee to the coffeemaker\n"
              << "Now, the current coffee amount is: "
              << currentCoffeeAmount << "\n";

  } else {
    std::cout << "HELP - this is too much coffee! We didn't add it.\n";
  }
}

bool CoffeeMaker::isFilled() {
  std::cout << "• Inside CoffeeMaker isFilled\n";
  // we interpreted filled as the coffee amount filled for [95%, 100%]
  if (currentCoffeeAmount > necessaryCoffeeAmount * 0.95) {
    return true;
  }
  return false;
}

bool CoffeeMaker::brew() {
  std::cout << "• Inside CoffeeMaker brew\n";
  // TODO  add check if the currentCoffeeAmount is large enough
  //      and then maybe post the strenght of a coffee, using a switch?
  // TODO - write method body
  return false;
}


// ____________________ main ____________________
int main() {
  // create CoffeeMaker object and call all its functions
  CoffeeMaker coffeeMaker("Moka pot", "Forever", 17);
  coffeeMaker.addCoffee(16.1);
  // call it again, add too much
  coffeeMaker.addCoffee(1.0);

  if(coffeeMaker.isFilled()) {
    std::cout << "There is enough coffee inside the coffeemaker.\n"
              << "We can now start brewing some decent coffee!\n";
  } else {
    std::cout << "There is NOT enough coffee inside the coffeemaker ... \n"
              << "We can start brewing, however, it will taste terrible.\n";
  }

  coffeeMaker.brew();

  // end program
  return 0;
}
