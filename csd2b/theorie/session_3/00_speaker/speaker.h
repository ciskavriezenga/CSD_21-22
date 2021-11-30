#include <iostream>
#include "woofer.h"
#include "tweeter.h"

class Speaker
{
public:
  Speaker();
  ~Speaker();
  void make_sound(float freq);
  float filter_freq; // filter cutoff frequency

  Tweeter tweeter;
  Woofer woofer_big;
  Woofer woofer_normal;

/*
  To do: add some speaker parts
  woofer
  tweeter
  amp
  filter
*/
};

