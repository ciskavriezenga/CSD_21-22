1. Juce - download

2. readme

3. git clone instead of download

4. continue reading readme.

5. check if cmake is installed and which version --> OK

6. test building example with cmake --> ???

7. open JUCE folder in atom, skim docs, skim examples folders

8. read docs - README, CMake API --> tells me to copy example projects
   + minor adoptations to get started

9. Let's first generate the documentation with doxygen as indicated in
   docs/README.md (first install missing dependencies doxygen and graphvizz)
   Reasons for local docs:
   • to save energy!
   (1 google search = 0,0003 kilowattuur (kWh) energie, 0,2 gram CO2
     = spaarlamp uur laten branden)
   • handig als internet 'down' is

10. Follow CMAKE API docs: "install juce globally" Build juce --> OK

11. cp esxample project & uncomment the call to `find_package`.

12. run 'cmake -Bbuild' --> errors "could not find packages" juce

13 install atom cmake syntax highlighting packages

14. global install --> 'dead end for now'  --> let's first try subdirectory

15. use 'add_subdirectory', then "cmake -B cmake-build-dir" and "cmake --build cmake-build-dir/"
(other option that works: "cmake -Bbuild"
TODO: read about how to use cmake)

16. run the example in cmake-build-dir GuiAppExample_artefacts --> "Hello world"

17. Try to add a button:
- search in reference for button --> let's make a TextButton
- add TextButton to class
- instantiate TextButton
- let's read ref about components (in MainComponent.h --> inherits from Component)
- ok, works, but not visible --> let's see if we need to adapt setSize
- no size in TextButton doc - but, inherits from Button which inherits Component
- Component reference -->
    - search position (he, there is a centerposition!)
    - search size --> let's set a hardcoded size
- hmm text does not view --> reread ref - skim size methods --> fit text!

18. ready for CSD session - shutting down. 
