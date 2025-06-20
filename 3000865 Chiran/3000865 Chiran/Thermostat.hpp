#ifndef THERMOSTAT_H
#define THERMOSTAT_H

#include "DeviceParent.hpp"

/**
 * @brief Class representing a thermostat device.
 * This class extends the ParentDevice class and adds attributes
 * specific to thermostats, such as target temperature.
 */

class Thermostat : public DeviceParent {
private:
    int mTargetTemperature; // Target temperature of the thermostat

public:

    /* @brief Constructor for Thermostat.
     * Initializes the thermostat with the provided attributes.
     * @param id The unique ID of the device.
     * @param name The name of the device.
     * @param manufacturer The manufacturer of the device.
     * @param temperature The target temperature of the thermostat.
     */

    Thermostat(int id, const std::string& name, const std::string& manufacturer, int temperature);

    /*
     * @brief Simulates user interaction with the thermostat.
     * Allows the user to set the target temperature.
     */

    void InteractionEvent() override;

    /* @brief Displays detailed information about the thermostat.
     * Outputs the device's ID, name, manufacturer, status, and target temperature.
     */

    void ViewInfo() const override;

    /** @brief setterfor target temperature.
     * sets The target temperature of the thermostat.
     */

    void SetTargetTemperature(int temperature) { mTargetTemperature = temperature; }

    /** @brief edit attributes.
     * sets allows you to edit attrubutes for thermostat.
     */
    void EditAttributes() override;
};

#endif // THERMOSTAT_H
