
# Theorie - session 1

## Overview CSD 2c
|   | Theorie                             |Code clinics               |
|---|---|---|
| 1 | Introductie, terugblik, tremolo     |Circular buffer            |
| 2 | Effect base class, delay            |Interpolatie               |
| 3 | Multi-threading en synchronisatie   |Interleaved & stereo audio |
| 4 | Computer Vision                     |Threads                    |
| 5 | Music Information Retrieval (MIR)   |Git branching              |
| 6 | Bela en sensoren                    |Feedback sessie            |
| 7 | Snippets en tests van eindopdracht  |Make & subfolers, STL      |
| 8 | Eindpresentatie                     |Ontwerpproces              |

## Effect base class, delay

## Opdrachten komende 3 weken - overzicht
week 1. Effect (base class), Delay, Tremolo classes
week 2. WaveShaper, presentatie voorbereiden - *presentatie theorie sessie week 3*
week 3. StereoChorus - *aftekenen practicum week 4*

## Opdracht - week 2
* Maak een waveshaper
  * maak gebruik van een wavetable
  * zie Pirkle page 497 voor een sigmoid functie

* Rond alle classes tot nu toe af - Effect base class en subclasses: Tremolo, Delay, Waveshaper en optioneel de losse class CircularBuffer.

* Creëer een demonstratie applicatie voor de console line, die deze effecten demonstreert met realtime audio input en output.

* Bereid een beknopte presentatie (max 4 min.) voor waarin je je demonstratie live
demonstreert. Gebruik hierbij een audio flow diagram om je effect chain inzichtelijk te maken en licht toe welke functionaliteiten wel / niet in je effecten verwerkt zijn (bijv. een smooth transition van de readhead in je Delay class wanneer de delay tijd wordt aangepast).
