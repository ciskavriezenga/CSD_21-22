<H1>Session 3</H1>

<H2>Content</H2>

* #### Makefiles  
  * making life easier :smiley:
    <u>**example 01_make**</u>
    In 8 steps we created a generic Makefil. See the files: Makefile1, ..., Makefile8.
    _NOTE: to use make, a makefile needs to be called "Makefile"_
    Additionally see: https://dinkum.nl/software/cplusplus/doc/project_building/make.html

* #### Initialiser list:  
  * initialiser list
  <u>**example: 02_initializerList**</u>
  _Additionally - not discussed during session, the example contains_
    * _an example of constructor Delegation_
    * _an example of the use of a static variable_

* #### Sine wave generation
  * Sine function  
  * Sine function in audio context
  <u>**see plotSine.R**</u> _we treated the generation of a sine wave in audio context step by step (.R file is a script in the R language)_

  * Sine in code example - plotting the resulting text output
  <u>**example: 03_sine**</u>

* #### Installing jack
  * sounding simple sine example
  <u>**example: 04_simpleSine**</u>
  _simple program meant to verify if you correctly installed jack and can work with audio output_
  <u>**example: 05_soundingSineClass**</u>
  _example that uses jack and uses a Sine object to generate an audible sinewave - you can use this example for the final assignment as a quickstart_

* #### Non treated / additional examples
  * 2 examples that show the issue with precision and why we need to wrap the phase to stay in the interval [0, 1]
  _we will look at these examples next week_
  <u>**example: 06_sin_function**</u>
  <u>**example: 07_precision**</u>
  * additional example - circular buffer
  <u>**example: 08_melody**</u>
  _containing an example of a very simplified circular buffer, which we did not treat yet!_

</br>
</br>
</br>

## Plotting
Multiple options exist to plot data.
\
The R language, or R-Studio:
https://www.datacamp.com/community/tutorials/installing-R-windows-mac-ubuntu
\
Or e.g. mathplotlib.
The directory 01_sine contains a python script that uses this library to plot the data.

```
pip3 install mathplotlib
cd 01_sine
python3 plot.py
```

\
<H3>Jackaudio</H3>

https://jackaudio.org/downloads/

https://github.com/jackaudio/jackaudio.github.com/wiki/jackd(1)
