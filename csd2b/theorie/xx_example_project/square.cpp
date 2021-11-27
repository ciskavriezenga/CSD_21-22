#include "square.h"

//Constructors and destructor
Square::Square(double samplerate) : Square(samplerate, 0, 0) {}

Square::Square(double samplerate, double frequency) :
  Square(samplerate, frequency, 0) {}

Square::Square(double samplerate, double frequency, double phase) :
  Oscillator (samplerate, frequency, phase) {}

Square::~Square() {}

//override calculate method
//this method contains the sample calculation
void Square::calculate()
{
  //TODO - use square function
  //NOTE sin() method is not the most efficient way to calculate the square value
  sample = sin(phase * PI_2 );
}
