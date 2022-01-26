
# Code Clinic 1.

#### Overview CSD 2c
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

* Inhoud code clinics


## CC1 - Circular Buffer
* functionaliteit
https://en.wikipedia.org/wiki/Circular_buffer
* wanneer nodig in M&T context?

  * ... zie ook uit boek Pirkle en .png:   
    "1. Read the output value, y(n), from the DDL and write it to the output buffer.
    2. Form the product fb * y(n).
    3. Write the input value, x(n) 1 fb * y(n), into the delay line." (W. Pirkle, 2013)


## CC1 - Opdracht
Maak een CircBuffer class die voldoet aan de volgende voorwaarden:
* De constructor format is:
    ```CircBuffer(uint size, uint numSamplesDelay)```
* Het aantal samples verschil tussen de read head en write head is aan te passen


##### *Voor diehards*
* de class CircBuffer bevat een functie ```resetSize(uint size)```, waarmee de buffer size aan te passen is.

##### *Voor die-diehards*
* bij het aanpassen van het aantal samples tussen de read en write head wordt de aanpassing over een gegeven aantal samples uitgesmeerd. In andere woorden, er wordt niet van de ene plek naar de andere plek in de buffer 'gesprongen' met de read head, maar de read head beweegt langzaam naar de nieuwe positie gedurende een gegeven aantal samples.


## References
* Pirkle, W. C. (2013). Designing Software Synthesizer Plug-ins in C++, With Digital Audio Signal Processing. Taylor and Francis Group (p.210)_
