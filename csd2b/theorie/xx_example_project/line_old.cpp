#include "line.h"


// default constructor is hidden
Line::Line(){}

Line::Line(Clock& clock) : Generator(clock), sampleStartValue(0),
  sampleEndValue(0), sampleStartIndex(0), sampleEndIndex(0), sampleDuration(0),
  lineIsRunning(false)
{}

Line::~Line()
{

}

void Line::calcNextSample()
{
  if(lineIsRunning) {
    // todo - update line
  }
}

void Line::setLine(double sampleEndValue, uint sampleDuration)
{
  // todo 
}

/*
 * TODO - add const value generator class for Oscillator amplitude that is
 * constant.
 * and change double amplitude in oscillator to Generator* type
 */
