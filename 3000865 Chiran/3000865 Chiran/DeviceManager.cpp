#include "DeviceManager.hpp"
#include <iostream>

// Constructor
DeviceHomeManager::DeviceHomeManager() {}

// Destructor
DeviceHomeManager::~DeviceHomeManager() {}
//Main menu
void DeviceHomeManager::Run() {
    int choice = 0;
    do {
        std::cout << "\nDevice Home Manager Menu:\n";
        std::cout << "1. List of all devices\n";
        std::cout << "2. Device Adder\n";
        std::cout << "3. Device Editor\n";
        std::cout << "4. Device Deleter\n";
        std::cout << "5. Device Controller\n";
        std::cout << "6. View connected devices\n";
        std::cout << "7. Exit\n";

        choice = GetValidIntegerInRange("Enter your choice: ", DeviceLimits::kMinMenuOption, DeviceLimits::kMaxMenuOption);

        switch (choice) {
        case MenuOptions::kListDevices:
            ListDevices();
            break;
        case MenuOptions::kAddDevice:
            AddDevice();
            break;
        case MenuOptions::kEditDevice:
            EditDevice();
            break;
        case MenuOptions::kDeleteDevice:
            DeleteDevice();
            break;
        case MenuOptions::kControlDevice:
            ControlDevice();
            break;
        case MenuOptions::kViewConnectedDevices:
            ViewConnectedDevices();
            break;
        case MenuOptions::kExit:
            std::cout << "Exiting...\n";
            break;
        }
    } while (choice != MenuOptions::kExit);
}
//List devices function
void DeviceHomeManager::ListDevices() const {
    if (mDevices.empty()) {
        std::cout << "No devices available.\n";
        return;
    }

    for (const auto& device : mDevices) {
        device->ViewInfo();
    }
}
//Add device function
void DeviceHomeManager::AddDevice() {
    int id = GetValidIntegerInput("Enter device ID: ");
    // Check for duplicate ID
    if (IsDuplicateID(id)) {
        std::cout << "Error: A device with this ID already exists. Please enter a unique ID.\n";
        return; // Exit the function without adding the device
    }
    std::string name = GetValidStringInput("Enter device name: ");
    std::string manufacturer = GetValidStringInput("Enter manufacturer: ");

    int type = GetValidIntegerInRange("Select device type (1: Security Camera, 2: Thermostat, 3: Smart Speaker, 4: Smart Light): ", DeviceTypes::kSecurityCamera, DeviceTypes::kSmartLight);

    std::unique_ptr<DeviceParent> newDevice;
    switch (type) {
    case 1: {
        std::string cameraQuality = GetValidStringFromList("Enter camera quality (720p, 1080p, 4k): ", { "720p", "1080p", "4k" });
        std::string powerSource = GetValidStringFromList("Enter power source (mains, battery, solar): ", { "mains", "battery", "solar" });
        newDevice = std::make_unique<SecurityCamera>(id, name, manufacturer, cameraQuality, powerSource);
        break;
    }
    case 2: {
        int targetTemperature = GetValidIntegerInput("Enter target temperature: ");
        newDevice = std::make_unique<Thermostat>(id, name, manufacturer, targetTemperature);
        break;
    }
    case 3: {
        int volumeLevel = GetValidIntegerInRange("Enter volume level (0-100): ", DeviceLimits::kMinVolumeLevel, DeviceLimits::kMaxVolumeLevel);
        newDevice = std::make_unique<SmartSpeaker>(id, name, manufacturer, volumeLevel);
        break;
    }
    case 4: {
        int brightnessLevel = GetValidIntegerInRange("Enter brightness level (0-100): ", DeviceLimits::kMinBrightnessLevel, DeviceLimits::kMaxBrightnessLevel);
        std::string colorType = GetValidStringFromList("Enter color type (warmWhite, coolWhite, RGB): ", { "warmWhite", "coolWhite", "RGB" });

        // If color type is RGB, let the user choose a specific color
        if (colorType == "RGB") {
            colorType = GetValidStringFromList("Choose a color (Red, Green, Blue, Yellow, Purple): ",
                { "Red", "Green", "Blue", "Yellow", "Purple" });
        }

        newDevice = std::make_unique<SmartLight>(id, name, manufacturer, brightnessLevel, colorType);
        break;
    }
    default:
        std::cout << "Invalid device type!\n";
        return;
    }

    mDevices.push_back(std::move(newDevice));
    std::cout << "Device added successfully!\n";
}
//Delete Device function
void DeviceHomeManager::DeleteDevice() {
    int id = GetValidIntegerInput("Enter device ID to delete: ");

    auto deviceIterator = std::find_if(mDevices.begin(), mDevices.end(), [id](const std::unique_ptr<DeviceParent>& device) {
        return device->GetID() == id;
        });

    if (deviceIterator != mDevices.end()) {
        mDevices.erase(deviceIterator);
        std::cout << "Device deleted.\n";
    }
    else {
        std::cout << "Device not found.\n";
    }
}
//COntrol device function
void DeviceHomeManager::ControlDevice() {
    int id = GetValidIntegerInput("Enter device ID to control: ");

    auto deviceIterator = std::find_if(mDevices.begin(), mDevices.end(), [id](const std::unique_ptr<DeviceParent>& device) {
        return device->GetID() == id;
        });

    if (deviceIterator != mDevices.end()) {
        int choice = GetValidIntegerInput("1. Activate\n2. Deactivate\n3. Interact\nEnter your choice: ");

        switch (choice) {
        case 1:
            (*deviceIterator)->Activate();
            break;
        case 2:
            (*deviceIterator)->Deactivate();
            break;
        case 3:
            (*deviceIterator)->InteractionEvent();
            break;
        default:
            std::cout << "Invalid choice!\n";
            break;
        }
    }
    else {
        std::cout << "Device not found.\n";
    }
}
//view connected devices function
void DeviceHomeManager::ViewConnectedDevices() const {
    bool found = false;
    for (const auto& device : mDevices) {
        if (device->CheckConnection()) {
            device->ViewInfo();
            found = true;
        }
    }

    if (!found) {
        std::cout << "No connected devices.\n";
    }
}
//edit device function
void DeviceHomeManager::EditDevice() {
    int id = GetValidIntegerInput("Enter device ID to edit: ");

    auto deviceIterator = std::find_if(mDevices.begin(), mDevices.end(), [id](const std::unique_ptr<DeviceParent>& device) {
        return device->GetID() == id;
        });

    if (deviceIterator != mDevices.end()) {
        (*deviceIterator)->EditAttributes();  // Call polymorphic method
        std::cout << "Device updated successfully!\n";
    }
    else {
        std::cout << "Device not found.\n";
    }
}
//duplicate id checker
bool DeviceHomeManager::IsDuplicateID(int id) const {
    for (const auto& device : mDevices) {
        if (device->GetID() == id) {
            return true; // Duplicate ID found
        }
    }
    return false; // No duplicate ID found
}