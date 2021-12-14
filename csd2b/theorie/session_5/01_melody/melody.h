#pragma once

#include <iostream>

#define NUM_NOTES 9

class Melody
{
public:
  Melody();
  ~Melody();

  // setters and getters
  float getPitch();

protected:
  // Cmaj7 -  arpeggio
  float melody[NUM_NOTES] = {60, 64, 67, 71, 64, 67, 64, 60, 55};
  // the index of the current note - readIndex
  int index;
};
