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


std::string retrieveUserInput(std::string selectionOptions[], int numOptions)
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

std::string retrieveUserSelection(std::string selectionOptions[], int numOptions)
{
    bool noCorrectSelection = true;
    std::string userSelection = "";
    while(noCorrectSelection) {
        // let user choice between the allowed options
        userSelection = retrieveUserInput(selectionOptions,
            numOptions);
        // check if the selection is correct
        noCorrectSelection = !validateSelection(userSelection, selectionOptions,
            numOptions);
        // if selection is not correct, log message to user to try again
        if(noCorrectSelection) {
            std::cout << "Incorrect selection, please try again";
        }
    }
    return userSelection;
}


float retrieveUserValue(float min, float max) {
  std::string input;
  float value = 0;
  bool notInRange = true;
  while(notInRange) {
    std::cout << "Please enter a value between " << min << " and " << max
      << std::endl;
    // first capture input in input string
    std::cin >> input;
    // validate if input string can be transformed into a float
    try {
      value = std::stof(input);
      if(value >= min && value <= max) {
        notInRange = false;
      } else {
        std::cout << "Incorrect range, please try again." << std::endl;
      }
    } catch (const std::exception& e) {
      std::cout << "Invalid input, this was not a number, please try again"
        << std::endl;
    }
  }

  return value;
}

int main()
{
    std::string waveFormOptions[4] = {"sine", "saw", "square", "triangle"};
    int numWaveFormOptions = 4;

    std::string waveTypeSelection = retrieveUserSelection(waveFormOptions,
        numWaveFormOptions);

    std::cout << "You selected: " << waveTypeSelection << std::endl;


    float value =  retrieveUserValue(20, 20499);
    std::cout << "You chose the following value: " << value << std::endl;

}
