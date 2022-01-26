#include <iostream>
#include <thread>
#include "jack_module.h"
#include "math.h"
#include "writeToFile.h"
#include "tremolo.h"

/*
 * NOTE: jack2 needs to be installed
 * jackd invokes the JACK audio server daemon
 * https://github.com/jackaudio/jackaudio.github.com/wiki/jackd(1)
 * on mac, you can start the jack audio server daemon in the terminal:
 * jackd -d coreaudio
 */

#define WRITE_TO_FILE 1
#define WRITE_NUM_SAMPLES 44100

int main(int argc,char **argv)
{

  // create a JackModule instance
  JackModule jack;

  // init the jack, use program name as JACK client name
  jack.init(argv[0]);
  float samplerate = jack.getSamplerate();
  float amplitude = 0.5;
  // create processbuffer that we can pass on to tremolo, init to 0
  float* procBuf = new float[samplerate];
  for(int i = 0; i < samplerate; i++) {
    procBuf[i] = 0;
  }

  // instantiate tremolo effect
  Tremolo tremolo(samplerate);

#if WRITE_TO_FILE
  WriteToFile fileWriter("data/output.csv", true);
  // assign a function to the JackModule::onProces
  jack.onProcess = [&procBuf, &amplitude, &tremolo, &fileWriter](jack_default_audio_sample_t* inBuf,
    jack_default_audio_sample_t* outBuf, jack_nframes_t nframes) {
#else
  // assign a function to the JackModule::onProces
  jack.onProcess = [&procBuf, &amplitude, &tremolo](jack_default_audio_sample_t* inBuf,
    jack_default_audio_sample_t* outBuf, jack_nframes_t nframes) {
#endif

    tremolo.process(inBuf, procBuf, nframes);
    // copy result to outBuf with given amplitude
    for(unsigned int i = 0; i < nframes; i++) {
      // ----- write result to file -----
#if WRITE_TO_FILE
      static int count = 0;
      if(count < WRITE_NUM_SAMPLES) {
        fileWriter.write(std::to_string(procBuf[i] * amplitude ) + "\n");
      } else {
        // log 'Done' message to console, only once
        static bool loggedDone = false;
        if(!loggedDone) {
          std::cout << "\n**** DONE **** \n"
            << "Output is written to file.\n"
            << "Please enter 'q' to quit the program." << std::endl;
          loggedDone = true;
        }
      }
      count++;
#else
      // ----- write result to output buffer -----
      outBuf[i] = procBuf[i] * amplitude;
#endif
    }

    return 0;
  };

  jack.autoConnect();

  //keep the program running and listen for user input, q = quit
  std::cout << "\n\nPress 'q' when you want to quit the program.\n";
  // boolean is used to keep program running / turn it off
  bool running = true;
  while (running)
  {
    switch (std::cin.get())
    {
      case 'q':
        running = false;
        jack.end();
        break;
      }
  }

  //end the program
  return 0;

} // main()
