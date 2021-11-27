#include <iostream>
#include <thread>
#include "jack_module.h"
#include "sine.h"
#include "saw.h"
#include "writeToFile.h"

#define WRITE_TO_FILE 1
#define WRITE__NUM_SAMPLES 2000
#define NUM_SINES 10
int main(int argc,char **argv)
{
  //create a JackModule instance
  JackModule jack;


  // init the jack, use program name as JACK client name
  jack.init(argv[0]);


  //create a Sine instance
  //Sine sine(jack.getSamplerate(), 220, 0);
  //Saw saw(jack.getSamplerate(), 50, 0);

  Sine *sines[NUM_SINES];
  double samplerate = jack.getSamplerate();
  double amplitude = 0.5 / NUM_SINES;
  for(int i = 0; i < NUM_SINES; i++) {
    sines[i] = new Sine(samplerate, 100.0 + i * 10, amplitude);
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

  //end the program
  return 0;
} // main()
