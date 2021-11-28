#include <iostream>
#include <thread>
#include "jack_module.h"
#include "sine.h"
#include "saw.h"
#include "writeToFile.h"

#define WRITE_TO_FILE 1
#define WRITE__NUM_SAMPLES 2000
#define NUM_SINES 50

#define AMPLITUDE_CALCULATION 0

int main(int argc,char **argv)
{
  //create a JackModule instance
  JackModule jack;


  // init the jack, use program name as JACK client name
  jack.init(argv[0]);


  Sine *sines[NUM_SINES];
  double samplerate = jack.getSamplerate();
  double baseFreq = 110;
  for(int i = 0; i < NUM_SINES; i++) {
    // calculate frequency of harmonic
    double offsetIndex = 1.0 + i;
    double freq = baseFreq * offsetIndex;
    //calculate the amplitude
#if AMPLITUDE_CALCULATION == 1
    // calculate the amplitude according sawtooth harmonics amplitude function
    // https://en.wikipedia.org/wiki/Sawtooth_wave
    // delimit the sawtooth with * 0.5, otherwise it exceeds [-1, 1]
    double amp = 0.5 * pow(-1.0,offsetIndex) / offsetIndex;
#elif AMPLITUDE_CALCULATION == 2
    // delimit amplitude for each harmonic
    double amp = 1.0 / pow(2, i + 1);
#else // use equal amplitude for each oscillator
    double amp = 0.9 / NUM_SINES;
#endif
    std::cout << "sine at index " << i << " - freq: " << freq
      << ", amp: " << amp << "\n";
    sines[i] = new Sine(samplerate, freq, amp);
  }


#if WRITE_TO_FILE
  // write 1 second of samples to file
  WriteToFile fileWriter("output.csv", true);
  int writeIndex = 0;
  jack.onProcess = [&sines, &fileWriter, &writeIndex](jack_default_audio_sample_t *inBuf,
     jack_default_audio_sample_t *outBuf, jack_nframes_t nframes)
#else
  jack.onProcess = [&sines](jack_default_audio_sample_t *inBuf,
     jack_default_audio_sample_t *outBuf, jack_nframes_t nframes)
#endif
  {
    //loop through frames, retrieve sample of sine per frame
    for(int i = 0; i < nframes; i++) {
      outBuf[i] = 0;
      for (int j = 0; j < NUM_SINES; j++) {
        outBuf[i] += sines[j]->getSample();
        sines[j]->tick();
      }

      // outBuf[i] = saw.getSample();
      // saw.tick();
#if WRITE_TO_FILE
      if(writeIndex < WRITE__NUM_SAMPLES) {
        fileWriter.write(std::to_string(outBuf[i]) + "\n");
        writeIndex++;
      }
#endif

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
