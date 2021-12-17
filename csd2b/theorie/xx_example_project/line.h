#pragma once

#include <iostream>
#include "Generator.h"

class Line : public Generator
{
public:
  Line();
    ~Line();

  // setters and getters
  void setLine(double sampleEndValue, uint sampleDuration);

private:
  void calcNextSample() override;

  // the value at the start and at the end
  double sampleStartValue;
  double sampleEndValue;

  // keep track of the sample start and end index of the line
  uint sampleEndIndex;
  uint sampleStartIndex;

  // using a double to save casting to double at every calculation
  double sampleDuration;

  // bool to simplify check if we need to update the line value or not
  bool lineIsRunning;

  // hide default constructor
  Line();
};
