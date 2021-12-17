#include <iostream>
#include "uiUtilities.h"
#include "audioManager.h"

int main(int argc,char **argv)
{
  AudioManager audioManager;




  //keep the program running and listen for user input, q = quit
  std::cout << "\n\nPress 'q' when you want to quit the program.\n";
  std::cout << "\n\nPress 'c' when you want to change the synthesizer.\n";
  bool running = true;
  while (running)
  {
    switch (std::cin.get())
    {
      case 'q':
        running = false;
        //audioManager.end();
        break;

      case 'c':
        audioManager.changeSynth();
        break;
    }
  }
}
