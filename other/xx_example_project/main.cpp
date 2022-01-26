#include <iostream>
#include <thread>
#include "macros.h"
#include "jack_module.h"
#include "sine.h"
#include "saw.h"
#include "writeToFile.h"



int main(int argc,char **argv)
{
  //create a JackModule instance
  JackModule jack;


  // init the jack, use program name as JACK client name
  jack.init(argv[0]);

  // create array to hold pointers to sine objects
  Sine *sines[NUM_SINES];

  // cache necessary values
  double samplerate = jack.getSamplerate();
  double baseFreq = 110;

  // create clock
  Clock clock(samplerate);

  // create sine objects dynamically
  for(int i = 0; i < NUM_SINES; i++) {
    // calculate frequency of harmonic
    double offsetIndex = 1.0 + i;
    double freq = baseFreq * offsetIndex;
    //calculate the amplitude
#if AMPLITUDE_CALCULATION == 1
    // calculate the amplitude according sawtooth harmonics amplitude function
    // https://en.wikipedia.org/wiki/Sawtooth_wave
    // delimit the end signal with * 0.5, otherwise it exceeds [-1, 1]
    double amp = 0.5 * pow(-1.0,offsetIndex) / offsetIndex;
#elif AMPLITUDE_CALCULATION == 2
    // delimit amplitude for each harmonic
    double amp = 1.0 / pow(2, i + 1);
#else // use equal amplitude for each oscillator
    double amp = 0.9 / NUM_SINES;
#endif
    std::cout << "sine at index " << i << " - freq: " << freq
      << ", amp: " << amp << "\n";
    // TODO - remove the samplerate from constructors
    sines[i] = new Sine(clock, freq, amp);
  }


#if WRITE_TO_FILE
  // write 1 second of samples to file
  WriteToFile fileWriter("output.csv", true);
  int writeIndex = 0;
  jack.onProcess = [&clock, &sines, &fileWriter, &writeIndex](jack_default_audio_sample_t *inBuf,
     jack_default_audio_sample_t *outBuf, jack_nframes_t nframes)
#else
  jack.onProcess = [&clock, &sines](jack_default_audio_sample_t *inBuf,
     jack_default_audio_sample_t *outBuf, jack_nframes_t nframes)
#endif
  {
    //loop through frames, retrieve sample of sine per frame
    for(int i = 0; i < nframes; i++) {
      // do not forget to clear the buffer! --> set to 0
      outBuf[i] = 0;
      for (int j = 0; j < NUM_SINES; j++) {
        outBuf[i] += sines[j]->getSample();
      }
      clock.tick();
#if WRITE_TO_FILE
      if(writeIndex < WRITE__NUM_SAMPLES) {
        fileWriter.write(std::to_string(outBuf[i]) + "\n");
        writeIndex++;
      }
#endif
      //std::cout << "output buf 0: " << outBuf[0] << std::endl;
    }
    return 0;
  };

  jack.autoConnect();

  //keep the program running and listen for user input, q = quit
  std::cout << "\n\nPress 'q' when you want to quit the program.\n";
  bool running = true;
  while (running)
  {
      switch (std::cin.get())
      {
          case 'q':
            running = false;
            break;
      }
  }

  // delete dynamically allocated sine objects
  for(int i = 0; i < NUM_SINES; i++) {
    delete sines[i];
    sines[i] = nullptr;
  }

  //end the program
  return 0;
} // main()
