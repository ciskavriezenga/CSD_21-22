#include <iostream>


bool validateSelection(std::string selection, std::string selectionOptions[],
    int numOptions)
{
    // check if the selection occurs inside the options, if so, return true
    for (int i = 0; i < numOptions; ++i) {
        if(selection == selectionOptions[i]) {
            return true;
        }
    }
    // selection does not occur in options --> return false
    return false;
}


std::string retrieveUserSelection(std::string selectionOptions[], int numOptions)
{
    // show user the allowed options
    std::cout << "Please enter your selection. You can choice between: ";
    for(int i = 0; i < numOptions - 1; i++) {
        std::cout << selectionOptions[i] << ", ";
    }
    // print last option outside forloop to end with an .
    std::cout << selectionOptions[numOptions - 1] << "." << std::endl;
    // retrieve and return choice
    std::string selection = "";
    std::cin >> selection;
    return selection;
}


int main()
{
    std::string waveFormOptions[4] = {"sine", "saw", "square", "triangle"};
    int numWaveFormOptions = 4;

    bool noCorrectSelection = true;
    std::string userSelection = "";
    while(noCorrectSelection) {
        // let user choice between the allowed options
        userSelection = retrieveUserSelection(waveFormOptions,
            numWaveFormOptions);
        // check if the selection is correct
        noCorrectSelection = !validateSelection(userSelection, waveFormOptions,
            numWaveFormOptions);
        // if selection is not correct, log message to user to try again
        if(noCorrectSelection) {
            std::cout << "Incorrect selection, please try again";
        }
    }

    std::cout << "You selected: " << userSelection << std::endl;

}
