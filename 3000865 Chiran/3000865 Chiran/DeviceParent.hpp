#ifndef DEVICEPARENT_HPP
#define DEVICEPARENT_HPP

#include <iostream>
#include <string>

/**
 * @brief THe base class for every other device class
 * This class provides methods and variables, for all devices,
 * such as activation, deactivation, and interaction events.
 */


class DeviceParent {
protected:
    int mIdNumber;              // unique id for each device
    std::string mDeviceName;    // devicename
    std::string mManufacturer;  // device manufacturer
    bool mStatus;               // whether the device is active or not

public:
    // Constructor for device parent
    DeviceParent(int id, const std::string& deviceName, const std::string& manufacturer);

    // Virtual Destructor
    virtual ~DeviceParent()=default;

    // Pure virtual function for device interaction
    virtual void InteractionEvent() = 0;

    // Activate and Deactivate the device
    void Activate();
    void Deactivate();

    // Display device information
    virtual void ViewInfo() const;

    // Check connection status
    bool CheckConnection() const;

    // Getters for device attributes
    int GetID() const;
    std::string GetName() const;
    std::string GetManufacturer() const;

    virtual void EditAttributes() = 0;
};

#endif // DEVICEPARENT_HPP

