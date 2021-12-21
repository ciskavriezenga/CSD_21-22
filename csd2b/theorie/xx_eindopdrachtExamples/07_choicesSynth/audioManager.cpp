#include "audioManager.h"
#include "AMSynth.h"
#include "detunedSynth.h"
#include "writeToFile.h"

#define WRITE_TO_FILE 0


AudioManager::AudioManager() : synth(nullptr)
{
#if WRITE_TO_FILE
  samplerate = 44100;
  // create synth based on user input
  changeSynth();
  writeToFile();
#else
  jack = new JackModule();
  jack->init("example");
  samplerate = jack->getSamplerate();
  // create synth based on user input
  changeSynth();
  // call method that handles assignment of onProcess function for JackModule
  assignAudioCallback();
  // start audio!
  jack->autoConnect();
#endif
}

AudioManager::~AudioManager()
{
  // if synth is assigned to dynamic allocated Synth object- delete it
  deleteSynth();
}

bool AudioManager::changeSynth()
{
  // create a string array with the synth type options
  std::string* synthTypeOptions = new std::string[SynthType::Size];
  for(int i = 0; i < SynthType::Size; i++) {
     synthTypeOptions[i] = synthTypeToString((SynthType)i);
  }

  // retrieve the user selection in form of an enum
  SynthType synthType = (SynthType)
    UIUtilities::retrieveSelectionIndex(synthTypeOptions, SynthType::Size);

  // release the dynamic synth array
  delete [] synthTypeOptions;
  synthTypeOptions = nullptr;

  // create the by the user selected synth type
  return changeSynth(synthType);
}

bool AudioManager::changeSynth(SynthType synthType)
{
  // if synth is assigned to dynamic allocated Synth object- delete it
  deleteSynth();

  // create a string array with the waveform type options
  std::string* waveformOptions = new std::string[Synth::Waveform::Size];
  for(int i = 0; i < Synth::Waveform::Size; i++) {
     waveformOptions[i] = Synth::waveformTypeToString((Synth::Waveform)i);
  }

  // retrieve the user selection in form of an enum
  Synth::Waveform waveformType = (Synth::Waveform)
    UIUtilities::retrieveSelectionIndex(waveformOptions, Synth::Waveform::Size);

  switch(synthType) {
    case AMSynthType:
      synth = new AMSynth(samplerate, waveformType);
      break;
    case DetunedSynthType:
      synth = new DetunedSynth(samplerate, waveformType);
      break;
    default:
      std::cout << "• AudioManager::changeSynth - unknown synth type" << std::endl;
      // failed assinging new synth
      return false;
  }

  return true;
}

void AudioManager::assignAudioCallback()
{
  // assign a function to the JackModule::onProces
  // NOTE: an empty process loop, just to log current synth
  jack->onProcess = [this](jack_default_audio_sample_t *inBuf,
    jack_default_audio_sample_t *outBuf, jack_nframes_t nframes) {

    // fill output buffer
    for(unsigned int i = 0; i < nframes; i++) {
      // write sample to output

      if(synth != nullptr) {
        outBuf[i] = synth->getSample();
        // calculate next sample
        synth->nextSample();
      } else {
        outBuf[i] = 0;
      }
    }
    return 0;
  };
}

void AudioManager::end()
{
  std::cout << "• AudioManager::end - ending jack process." << std::endl;
  jack->end();
}

std::string AudioManager::synthTypeToString(SynthType type)
{
  switch(type) {
  case AMSynthType:
      return "AMSynth";
    case DetunedSynthType:
      return "DetunedSynth";
    default:
      return "Invalid Synth";
  }
}

void AudioManager::writeToFile()
{
  WriteToFile fileWriter("output.csv", true);

  for(int i = 0; i < 1000; i++) {
    fileWriter.write(std::to_string(synth->getSample()) + "\n");
    synth->nextSample();
  }
}


void AudioManager::deleteSynth()
{
  if(synth != nullptr) {
    // delete current synth
    delete synth;
    synth = nullptr;
  }
}
