#ifndef DEVICEMANAGER_HPP
#define DEVICEMANAGER_HPP

#include "DeviceParent.hpp"
#include "SecurityCamera.hpp"
#include "Thermostat.hpp"
#include "SmartSpeaker.hpp"
#include "SmartLight.hpp"
#include "InputValidation.hpp"
#include <vector>
#include <memory>

/**
 * @namespace MenuOptions
 * @brief Defines constants for menu choices in the smart home manager.
 */
namespace MenuOptions {
    const int kListDevices = 1;          ///< Option to list all devices.
    const int kAddDevice = 2;            ///< Option to add a new device.
    const int kEditDevice = 3;           ///< Option to edit an existing device.
    const int kDeleteDevice = 4;         ///< Option to delete a device.
    const int kControlDevice = 5;        ///< Option to control a device.
    const int kViewConnectedDevices = 6; ///< Option to view connected devices.
    const int kExit = 7;                 ///< Option to exit the program.
}

/**
 * @namespace DeviceLimits
 * @brief Defines various limits for device attributes and menu options.
 */
namespace DeviceLimits {
    const int kMinMenuOption = 1;      ///< Minimum menu option value.
    const int kMaxMenuOption = 7;      ///< Maximum menu option value.
    const int kMinVolumeLevel = 0;     ///< Minimum volume level for a smart speaker.
    const int kMaxVolumeLevel = 100;   ///< Maximum volume level for a smart speaker.
    const int kMinBrightnessLevel = 0; ///< Minimum brightness level for a smart light.
    const int kMaxBrightnessLevel = 100; ///< Maximum brightness level for a smart light.
}

/**
 * @namespace DeviceTypes
 * @brief Defines constants for different device types.
 */
namespace DeviceTypes {
    const int kSecurityCamera = 1; ///< Identifier for a security camera.
    const int kThermostat = 2;     ///< Identifier for a thermostat.
    const int kSmartSpeaker = 3;   ///< Identifier for a smart speaker.
    const int kSmartLight = 4;     ///< Identifier for a smart light.
}

/**
 * @class DeviceHomeManager
 * @brief Manages smart home devices, allowing users to add, edit, delete, and control them.
 */
class DeviceHomeManager {
private:
    std::vector<std::unique_ptr<DeviceParent>> mDevices; ///< Container for storing smart devices.

public:
    /**
     * @brief Constructor for DeviceHomeManager.
     */
    DeviceHomeManager();

    /**
     * @brief Destructor for DeviceHomeManager.
     */
    ~DeviceHomeManager();

    /**
     * @brief Displays the main menu and processes user commands.
     */
    void Run();

    /**
     * @brief Displays a list of all devices.
     */
    void ListDevices() const;

    /**
     * @brief Allows the user to add a new device.
     */
    void AddDevice();

    /**
     * @brief Allows the user to edit an existing device.
     */
    void EditDevice();

    /**
     * @brief Removes a device from the list based on user input.
     */
    void DeleteDevice();

    /**
     * @brief Allows the user to control a device (e.g., activate, deactivate, interact).
     */
    void ControlDevice();

    /**
     * @brief Displays all currently connected devices.
     */
    void ViewConnectedDevices() const;
    /**
     * @brief Checks for duplicated id.
     */
    bool IsDuplicateID(int id) const;
        
        
};

#endif // DEVICEMANAGER_HPP
