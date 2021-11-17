#include <iostream>

// ____________________ CoffeeMaker class definition ____________________

class CoffeeMaker
{
public:
  CoffeeMaker();
  ~CoffeeMaker();
};

// ____________________ CoffeeMaker class implementation ____________________

CoffeeMaker::CoffeeMaker() {
  std::cout << "Inside CoffeeMaker constructor\n";
  // TODO - add parameters and initilize values, some based on these parameters
}

CoffeeMaker::~CoffeeMaker() {
  std::cout << "Inside CoffeeMaker destructor\n";
}

// ____________________ main ____________________
int main() {
  CoffeeMaker coffeeMaker;

  // end program
  return 0;
}
