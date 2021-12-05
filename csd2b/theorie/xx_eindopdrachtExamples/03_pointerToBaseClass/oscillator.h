#pragma once

#include <iostream>

class Oscillator
{
public:
  Oscillator();
  virtual ~Oscillator();

  virtual void calculate() = 0;
};
