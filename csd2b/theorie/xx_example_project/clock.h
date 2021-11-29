#include <iostream>

class Clock {
public:
  Clock(double samplerate) : samplerate(samplerate), clockIndex(0) {};
  //prevent the default constructor to be generated
  Clock() = delete;
  ~Clock(){};

  void tick() {
    clockIndex++;
  };

// getters & setters
  double getSamplerate() { return samplerate; };
  uint getClockIndex() { return clockIndex; };

private:
  double samplerate;
  uint clockIndex;
};
