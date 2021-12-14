#include "saw.h"
#include "sine.h"


int main()
{
  int size = 10;
  int count = 0;
  Sine** osc = new Sine*[size];

  int numOscs = 3;
  // dynamically allocate sines
  for(int i = 0; i < numOscs; i++) {
    osc[i] = new Sine();
  }
  count = numOscs;

  for(int i = 0; i < count; i++) {
    std::cout << "calc run 1 - index: " << i << std::endl;
    osc[i]->calculate();
  }

  osc[count++] = new Sine();

  for(int i = 0; i < count; i++) {
    std::cout << "calc run 2 - index: " << i << std::endl;
    osc[i]->calculate();
  }

  for(int i = 0; i < count; i++) {
    std::cout << "delete - index: " << i << std::endl;
    delete osc[i];
    osc[i] = nullptr;
  }

  delete [] osc;
  osc = nullptr;
}
