#pragma once

#include <iostream>


class CircBuffer {
public:
  CircBuffer(int size, int numSamplesDelay);
  ~CircBuffer();

  void write(float value);
  float read();

private:
  // NOTE: better to use a reference instead of return value
  // TODO - make inline method instead
  int wrapH(int head);
  int getDistanceRW();
  int readH;
  int writeH;
  int size;
  int numSamplesDelay;
  float* buffer;
};
