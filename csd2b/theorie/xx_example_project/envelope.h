/*
 * class Envelope
 *
 * by F. Vriezenga, dec 2021
 */

#include "generator.h"

class Envelope : public Generator {

public:
  Envelope(Clock* clock, double* ampValues, double* durValues,
    int numValues);
  virtual ~Envelope();

	//____________ PUBLIC METHODS ____________
	void Tick() override;
	//start or reset adsr
	void run();

protected:
	//____________ PROTECTED METHODS ____________
  // calcuate the slope for the current set of values
	void calculateSlope() {

	//calculates the next sample
	void calculateSample();
	int nextIndex();

private:
  // pointer to dynamic array of doubles
  double* ampValues;
  double* durValues;

  int numValues;
  int currentIndex = -1;
  double phase = 0;
  double phaseIncrement = 0;
  double slope = 0;
  double startValue = 0;
  double endValue = 0;
}
