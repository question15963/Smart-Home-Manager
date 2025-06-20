#include "SecurityCamera.hpp"
#include <iostream>
#include"InputValidation.hpp"

//constructor for device camera
SecurityCamera::SecurityCamera(int id, const std::string& name, const std::string& manufacturer, const std::string& cameraQuality, const std::string& power)
    : DeviceParent(id, name, manufacturer), mCameraQuality(cameraQuality), mPower(power) {}

//Interaction event for security camera
void SecurityCamera::InteractionEvent() {
    if (mStatus == true)
        std::cout << "Now viewing camera: " << mDeviceName << std::endl;
    else
        std::cout << "Camera not activated" << std::endl;
}

//view info for security ccamera
void SecurityCamera::ViewInfo() const {
    DeviceParent::ViewInfo();
    std::cout << "Camera Quality: " << mCameraQuality << ", Power Source: " << mPower << std::endl;
}
//function to edit attributes in security camera
void SecurityCamera::EditAttributes() {
    std::cout << "Editing Security Camera attributes.\n";
    std::string newName = GetValidStringInput("Enter new device name: ");
    std::string newManufacturer = GetValidStringInput("Enter new manufacturer: ");
    std::string cameraQuality = GetValidStringFromList("Enter camera quality (720p, 1080p, 4k): ", { "720p", "1080p", "4k" });
    std::string powerSource = GetValidStringFromList("Enter power source (mains, battery, solar): ", { "mains", "battery", "solar" });

    mDeviceName = newName;
    mManufacturer = newManufacturer;
    mCameraQuality = cameraQuality;
    mPower = powerSource;
}
