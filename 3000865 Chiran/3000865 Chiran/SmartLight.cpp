#include "SmartLight.hpp"
#include <iostream>
#include "InputValidation.hpp"
#include"DeviceManager.hpp"

//constructor for smart light
SmartLight::SmartLight(int id, const std::string& name, const std::string& manufacturer, int brightness, const std::string& color)
    : DeviceParent(id, name, manufacturer), mBrightnessLevel(brightness), mColorType(color) {}

//interaction event for smart light
void SmartLight::InteractionEvent() {
    if (mStatus == true) {
        std::cout << "Setting brightness to " << mBrightnessLevel << " and color to " << mColorType << std::endl;
    }
    else {
        std::cout << "Activate the light first!" << std::endl;
    }
}
//view info for smart light
void SmartLight::ViewInfo() const {
    DeviceParent::ViewInfo();
    std::cout << "Brightness Level: " << mBrightnessLevel << ", Color Type: " << mColorType << std::endl;
}
//edit attributes for smart light
void SmartLight::EditAttributes() {
    std::cout << "Editing Smart Light attributes.\n";
    std::string newName = GetValidStringInput("Enter new device name: ");
    std::string newManufacturer = GetValidStringInput("Enter new manufacturer: ");
    int brightnessLevel = GetValidIntegerInRange("Enter brightness level (0-100): ", DeviceLimits::kMinBrightnessLevel, DeviceLimits::kMaxBrightnessLevel);
    std::string colorType = GetValidStringFromList("Enter color type (warmWhite, coolWhite, RGB): ", { "warmWhite", "coolWhite", "RGB" });

    mDeviceName = newName;
    mManufacturer = newManufacturer;
    mBrightnessLevel = brightnessLevel;
    mColorType = colorType;

    // If color type is RGB, let the user choose a color from a list of 5 predefined colors
    if (mColorType == "RGB") {
        std::string color = GetValidStringFromList("Choose a color (Red, Green, Blue, Yellow, Purple): ",
            { "Red", "Green", "Blue", "Yellow", "Purple" });
        mColorType = color; // Update the color type to the chosen color
    }
}