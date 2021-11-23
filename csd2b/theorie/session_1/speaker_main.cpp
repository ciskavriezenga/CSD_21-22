#include "speaker.h"

int main()
{
  Speaker speaker_left;
  Speaker speaker_right;

  speaker_left.make_sound();
  speaker_left.filter_freq=728.5;
  speaker_left.make_sound();
}

