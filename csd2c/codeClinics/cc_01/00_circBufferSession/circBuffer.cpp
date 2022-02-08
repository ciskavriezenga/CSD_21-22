#include "circBuffer.h"


CircBuffer::CircBuffer(int size, int numSamplesDelay) :
  readH(size - numSamplesDelay), writeH(0),
  size(size), numSamplesDelay(numSamplesDelay)
{
  if(numSamplesDelay > size) {
    throw ("CircBuffer::CircBuffernumSamplesDelay exceeds size.");
  }
  // initialize buffer array
  buffer = new float[size];
  // initilize array with 0
  for(int i = 0; i < size; i++) {
    buffer[i] = 0;
  }
}

CircBuffer::~CircBuffer()
{
  // release the dynamic allocated array
  delete [] buffer;
}

void CircBuffer::write(float value)
{
  // TODO - be sure that we do not surpass the readH
  // use getDistanceRW method to check
  buffer[writeH++] = value;
  writeH = wrapH(writeH);
}

float CircBuffer::read()
{
  float value = buffer[readH++];
  readH = wrapH(readH);
  return value;
}

int CircBuffer::wrapH(int head)
{
  if(head >= size) head -= size;
  return head;
}

int CircBuffer::getDistanceRW()
{
  /*
   * NOTE: two scenarios:
   *  • writeH > readH
   *  • writeH < readH
   * we want the first situation,
   *    thus, if writeH < readH --> add size to writeH
   */

   if(writeH < readH) {
     int tempWH = writeH;
     tempWH += size;
     return tempWH - readH;
   }
   return writeH - readH;
}
