
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

## Tremelo Effect


## Opdrachten komende 3 weken - overzicht
week 1. Effect (base class), Delay, Tremolo classes
week 2. WaveShaper, presentatie voorbereiden
week 3. StereoChorus

## Opdracht - week 1
Werk de volgende classes uit
* Effect (base class)
* Effect subclasses:
  * Delay (met circular buffer als losse class _(has a relationship)_ of circular buffer functionaliteit rechtstreeks in de class zelf), met:
    * instelbare feedback signaal
    * met instelbare dry en wet
    * instelbare delay tijd in samples
    * instelbare delay tijd in (m)seconden

    ##### *Voor diehards*
      * bij het aanpassen van de delay tijd wordt de aanpassing over een gegeven aantal samples uitgesmeerd. In andere woorden, er wordt niet van de ene plek naar de andere plek in de buffer 'gesprongen' met de read head, maar de read head beweegt langzaam naar de nieuwe positie gedurende een gegeven aantal samples.

  * Tremolo
    * met modDepth
