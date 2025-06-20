#include "InputValidation.hpp"


//function to get a valid integer input from user

int GetValidIntegerInput(const std::string& prompt) {
    int value;
    while (true) {
        std::cout << prompt;
        if (std::cin >> value) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Clear input buffer
            return value;
        }
        else {
            std::cin.clear();  // Clear error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Ignore invalid input
            std::cout << "Invalid input! Please enter a valid number.\n";
        }
    }
}
//function to get a valid string input from user

std::string GetValidStringInput(const std::string& prompt) {
    std::string value;
    while (true) {
        std::cout << prompt;
        std::getline(std::cin, value);

        if (!value.empty()) {
            return value;
        }
        else {
            std::cout << "Input cannot be empty! Please enter a valid string.\n";
        }
    }
}

//function to get a valid number from a range input from user
int GetValidIntegerInRange(const std::string& prompt, int min, int max) {
    int value;
    while (true) {
        std::cout << prompt;
        if (std::cin >> value && value >= min && value <= max) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear buffer
            return value;
        }
        else {
            std::cin.clear(); // Clear error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore invalid input
            std::cout << "Invalid input! Please enter a number between " << min << " and " << max << ".\n";
        }
    }
}
//function to get a string from a range input from user
std::string GetValidStringFromList(const std::string& prompt, const std::vector<std::string>& validOptions) {
    std::string input;
    while (true) {
        std::cout << prompt;
        std::getline(std::cin, input);

        for (const std::string& option : validOptions) {
            if (input == option) {
                return input;
            }
        }

        std::cout << "Invalid input! Allowed options are: ";
        for (const std::string& option : validOptions) {
            std::cout << option << " ";
        }
        std::cout << "\n";
    }
}

