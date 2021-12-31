#include "Envelope.h"




Envelope::Evelope(Clock clock, double* ampValues, double* durValues,
  int numValues) {
    this.ampValues = ampValues;
    this.durValues = durValues;
    this.numValues = numValues;
  }

Envelope::~Envelope() {
  delete []ampValues;
  ampValues = nullptr
  delete []durValues;
  durValues = nullptr
}

//____________ PUBLIC METHODS ____________
void Envelope::Tick()
{
	//if envelope is running
	if (currentIndex != -1) {
		//increment phase
		phase += phaseIncrement;
		//check if phase exceeds end
		if (phase > 1.0) {
			//either we are ready to start next slope or we are done
			if (nextIndex () != -1) {
				calculateSlope ();
			} else {
				//done with envelope, don't calculate sample
				return;
			}
		}
		calculateSample ();
	}
}

//start or reset adsr
void Envelope::run() {
	currentIndex = 0;
	calculateSlope();
}


//____________ PROTECTED METHODS ____________
void Envelope::calculateSlope() {
	//be sure were not at the end of the envelope
	if (currentIndex >= 0 && currentIndex + 1 < numValues) {
		startValue = ampValues[currentIndex];
		endValue = ampValues [currentIndex + 1];
		phase = 0;
		phaseIncrement = 1 / (samplerate * durValues [currentIndex]);
		slope = endValue - startValue;
	} else {
		//.... at end or something gone wrong.
		Debug.Log("Envelope.calculateSlope -> something gone wrong???");
	}
}


//calculates the next sample
void Envelope::calculateSample() {
	sample = startValue + phase * slope;
}

int Envelope::nextIndex() {
	currentIndex++;
	if (currentIndex + 1 >= numValues) {
		currentIndex = -1;
		sample = 0;
	}
	return currentIndex;
}
