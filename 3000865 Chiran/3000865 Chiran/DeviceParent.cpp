#include "DeviceParent.hpp"

/*@brief Constructor for DeviceParent base class
 * i used initialization list to inilialize all the variables in the constructor
 * @param id The unique ID of the device.
 * @param name The name of the device.
 * @param manufacturer The manufacturer of the device.
 * @parem status is inactive since all devices must be inactive as mentioned in the assignement
 */

DeviceParent::DeviceParent(int id, const std::string& name, const std::string& manufacturer)
    : mIdNumber(id), mDeviceName(name), mManufacturer(manufacturer), mStatus(false) {} //used initialization list


/* @brief Activates the device.
 * Sets the device status to active.
 */

void DeviceParent::Activate() {
    mStatus = true;
}

/* @brief Deactivates the device.
 * Sets the device status to inactive (false)
 */

void DeviceParent::Deactivate() {
    mStatus = false;
}

/* @brief Displays device information.
 * Outputs the device's ID, name, manufacturer, and status.
 */

void DeviceParent::ViewInfo() const {
    std::cout << "ID: " << mIdNumber << ", Name: " << mDeviceName
        << ", Manufacturer: " << mManufacturer
        << ", Status: " << (mStatus ? "Active" : "Inactive") << '\n';
}

/** @brief Checks if the device is active or not.
 * @return True if the device is active, false otherwise.
 */

bool DeviceParent::CheckConnection() const {
    return mStatus;
}

/* @brief Getter for device ID.
 * @return The unique ID of the device.
 */

int DeviceParent::GetID() const {
    return mIdNumber;
}

/* @brief Getter for device name.
 * @return The name of the device.
 */

std::string DeviceParent::GetName() const {
    return mDeviceName;
}

/*
 * @brief Getter for manufacturer name.
 * @return The manufacturer of the device.
 */

std::string DeviceParent::GetManufacturer() const {
    return mManufacturer;
}