//All credits for writeToFile, Sine and basically all the other types of oscillators
//go to Ciska Vriezenga https://github.com/ciskavriezenga/CSD_21-22/tree/master/csd2b/theorie/session_3
//Credits for Jack audio implementation go to Marc Groenewegen and Ciska Vriezenga
#include <iostream>
#include "saw.h"
using namespace std;

Saw::Saw(double frequency, double samplerate) : Oscillator(frequency, samplerate){
    cout<< "constructor Saw" <<endl;
}

Saw::~Saw(){
    cout<< "destructor Saw" <<endl;
}

void Saw::calculate(){
    sample = (phase * 2 -1);
}
