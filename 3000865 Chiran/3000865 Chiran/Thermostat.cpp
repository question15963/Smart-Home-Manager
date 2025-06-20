#include "Thermostat.hpp"
#include <iostream>
#include"InputValidation.hpp"


//thermostat constructor
Thermostat::Thermostat(int id, const std::string& name, const std::string& manufacturer, int temperature)
    : DeviceParent(id, name, manufacturer), mTargetTemperature(temperature) {}

//interaction event for smart light
void Thermostat::InteractionEvent() {
    if (mStatus == true)
        std::cout << "Thermostat is set to " << mTargetTemperature << " degrees" << std::endl;
    else
        std::cout << "Thermostat is not activated" << std::endl;
}
//view info for smart light
void Thermostat::ViewInfo() const {
    DeviceParent::ViewInfo();
    std::cout << "Target Temperature: " << mTargetTemperature << " degrees" << std::endl;
}
// function to edit attribures
void Thermostat::EditAttributes() {
    std::cout << "Editing Thermostat attributes.\n";
    std::string newName = GetValidStringInput("Enter new device name: ");
    std::string newManufacturer = GetValidStringInput("Enter new manufacturer: ");
    int targetTemperature = GetValidIntegerInput("Enter target temperature: ");

    mDeviceName = newName;
    mManufacturer = newManufacturer;
    mTargetTemperature = targetTemperature;
}