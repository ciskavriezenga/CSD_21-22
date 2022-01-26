#pragma once

#include <iostream>
#include "envelope.h"

class Line : public Envelope
{
public:
  LineClock(Clock* clock, double startValue, double lineDuration);
  ~Line();
};
