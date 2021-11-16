#include <iostream>

class Speaker
{
public:
  Speaker();
  ~Speaker();
  void make_sound();
  float filter_freq; // filter cutoff frequency
/*
  To do: add some speaker parts
  woofer
  tweeter
  amp
  filter
*/
};

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

int main()
{
  Speaker speaker_left;
  Speaker speaker_right;

  speaker_left.make_sound();
  speaker_left.filter_freq=728.5;
  speaker_left.make_sound();
}

