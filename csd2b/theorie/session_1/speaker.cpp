#include "speaker.h"

Speaker::Speaker()
{
  std::cout << "Constructor called" << std::endl;
  filter_freq=307.2; // filter cutoff frequency
}

Speaker::~Speaker()
{
  std::cout << "Destructor called" << std::endl;
}

void Speaker::make_sound() 
{
  std::cout << "Tadaaa" << std::endl;
  std::cout << "Filter frequency: " << filter_freq << std::endl;
}
