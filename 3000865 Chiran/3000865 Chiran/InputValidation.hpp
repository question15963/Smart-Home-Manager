#ifndef INPUT_VALIDATION_HPP
#define INPUT_VALIDATION_HPP

#include <iostream>
#include <limits>
#include <string>
#include <vector>

/**
 * @brief Get a valid integer input from the user.
 * @param prompt The message displayed before input.
 * @return A valid integer value.
 */
int GetValidIntegerInput(const std::string& prompt);

/**
 * @brief Get a valid string input from the user.
 * @param prompt The message displayed before input.
 * @return A valid string value.
 */
std::string GetValidStringInput(const std::string& prompt);


/**
 * @brief Get a valid integer input within a specified range.
 * @param prompt The message displayed before input.
 * @param min The minimum acceptable value.
 * @param max The maximum acceptable value.
 * @return A valid integer within the given range.
 */
int GetValidIntegerInRange(const std::string& prompt, int min, int max);

/**
 * @brief Get a valid string input from a predefined list of options.
 * @param prompt The message displayed before input.
 * @param validOptions A vector containing valid string options.
 * @return A valid string from the list of options.
 */
std::string GetValidStringFromList(const std::string& prompt, const std::vector<std::string>& validOptions);

#endif // INPUT_VALIDATION_HPP
