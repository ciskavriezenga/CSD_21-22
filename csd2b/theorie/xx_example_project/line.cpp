#include "line.h"

Line::Line(Clock* clock, double startValue, double lineDuration) :
  Generator(clock, {startValue, startValue}, {lineDuration}, 2)
{}
Line::~Line() {}
