#include "melody.h"

Melody::Melody()
{}

Melody::~Melody()
{}

float Melody::getPitch()
{
  // wrap index
  if(index >= NUM_NOTES) {
    index = 0;
  }
  // index++ --> first use current value to read from array, after this
  // increment with 1
  return melody[index++];
}
