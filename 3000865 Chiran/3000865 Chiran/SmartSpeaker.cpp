#include "SmartSpeaker.hpp"
#include <iostream>
#include "InputValidation.hpp"
#include"DeviceManager.hpp"

//smart speaker constructor
SmartSpeaker::SmartSpeaker(int id, const std::string& name, const std::string& manufacturer, int volumeLevel)
    : DeviceParent(id, name, manufacturer), mVolumeLevel(volumeLevel) {}

//interaction event for smart light
void SmartSpeaker::InteractionEvent() {
    if (mStatus == true)
        std::cout << "Setting volume level to " << mVolumeLevel << std::endl;
    else
        std::cout << "Activate the speaker first!" << std::endl;
}

//view info for smart light
void SmartSpeaker::ViewInfo() const {
    DeviceParent::ViewInfo();
    std::cout << "Volume Level: " << mVolumeLevel << std::endl;
}
// function to edit attributes in smart light
void SmartSpeaker::EditAttributes() {
    std::cout << "Editing Smart Speaker attributes.\n";
    std::string newName = GetValidStringInput("Enter new device name: ");
    std::string newManufacturer = GetValidStringInput("Enter new manufacturer: ");
    int volumeLevel = GetValidIntegerInRange("Enter volume level (0-100): ", DeviceLimits::kMinVolumeLevel, DeviceLimits::kMaxVolumeLevel);

    mDeviceName = newName;
    mManufacturer = newManufacturer;
    mVolumeLevel = volumeLevel;
}