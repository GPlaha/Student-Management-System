#include "../include/utilities.h"
#include <iostream>
#include <string>

void utilities::ignoreCin() // function to ignore buffers
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
/**
 * @brief Asks a user for a number, then converts the inputted
 * string into a number and returns that number if successful
 *
 * @param message the message to be displayed when asking the user for an input
 * @return int the number that the user entered
 */
int utilities::getNumberFunction(std::string message)
{
    int inputtedNumber;
    std::string userInput;
    while (true)
    {
        std::cout << message;
        std::cin >> userInput;
        ignoreCin();

        try
        {
            inputtedNumber = stoi(userInput); // string has been converted to int type --  try-catch for error handling
            // trying to convert the string into a interget and if it fails we want to try and catch it and if it succeeds we want to return the inputted number
            return inputtedNumber;
        }

        catch (...)
        {
            std::cout << "Input not recognised, please enter a number: " << std::endl;
        }
    }
}

std::string utilities::getStringFunction(std::string message)
{
    std::string inputtedString;
    std::cout << message;
    // std::cin >> inputtedString;
    std::getline(std::cin, inputtedString);
    // ignoreCin();

    return inputtedString;
}
