#include <iostream>
#include <thread>
#include "jack_module.h"
#include "math.h"
#include "writeToFile.h"
#include "tremolo.h"
#include "delay.h"

/*
 * NOTE: jack2 needs to be installed
 * jackd invokes the JACK audio server daemon
 * https://github.com/jackaudio/jackaudio.github.com/wiki/jackd(1)
 * on mac, you can start the jack audio server daemon in the terminal:
 * jackd -d coreaudio
 */

#define WRITE_TO_FILE 0
#define WRITE_NUM_SAMPLES 44100

int main(int argc,char **argv)
{

  // create a JackModule instance
  JackModule jack;

  // init the jack, use program name as JACK client name
  jack.init(argv[0]);
  float samplerate = jack.getSamplerate();
  float amplitude = 0.5;

  // instantiate tremolo effect
  Tremolo tremolo(samplerate);
  Delay delay(0.5, WRITE_NUM_SAMPLES / 4.0, WRITE_NUM_SAMPLES, 0.5);

#if WRITE_TO_FILE
  WriteToFile fileWriter("output.csv", true);
  // assign a function to the JackModule::onProces
  jack.onProcess = [&amplitude, &tremolo, &delay, &fileWriter](jack_default_audio_sample_t* inBuf,
    jack_default_audio_sample_t* outBuf, jack_nframes_t nframes) {
#else
  // assign a function to the JackModule::onProces
  jack.onProcess = [&amplitude, &tremolo, &delay](jack_default_audio_sample_t* inBuf,
    jack_default_audio_sample_t* outBuf, jack_nframes_t nframes) {
#endif
    for(unsigned int i = 0; i < nframes; i++) {
      outBuf[i] = tremolo.processFrame(inBuf[i]);
      outBuf[i] = delay.processFrame(outBuf[i]);
      outBuf[i] *= amplitude;

      // ----- write result to file -----
#if WRITE_TO_FILE
      static int count = 0;
      if(count < WRITE_NUM_SAMPLES) {
        fileWriter.write(std::to_string(outBuf[i]) + "\n");
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
      // set output to 0 to prevent issues with output
      outBuf[i] = 0;
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
