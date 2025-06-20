#ifndef SMARTLIGHT_HPP
#define SMARTLIGHT_HPP

#include "DeviceParent.hpp"

/** @brief Class for smart light
 * attributes and methods for smart light
 */

class SmartLight : public DeviceParent {
private:
    int mBrightnessLevel; // Brightness level of the smart light (0-100)
    std::string mColorType; // Color type of the smart light (e.g., warm white, cool white, RGB)

public:

    /* @brief Constructor for SmartLight.
     * Initializes the smart light with the provided attributes.
     * @param id The unique ID of the device.
     * @param name The name of the device.
     * @param manufacturer The manufacturer of the device.
     * @param brightness The brightness level of the smart light.
     * @param color The color type of the smart light.
     */

    SmartLight(int id, const std::string& name, const std::string& manufacturer, int brightness, const std::string& color);

    /*
     * @brief Simulates user interaction with the smart light.
     * Allows the user to set the brightness level and choose a color (if RGB).
     */

    void InteractionEvent() override;

    /*
     * @brief Displays detailed information about the smart light.
     * Outputs the device's ID, name, manufacturer, status, brightness level, and color type.
     */

    void ViewInfo() const override;

    /*
     * @brief setters needed to set brightness and colortype.
     * lets you set brightneess and the color type
     */
    
    void SetBrightnessLevel(int brightness) { mBrightnessLevel = brightness; }
    void SetColorType(const std::string& color) { mColorType = color; }

    /** @brief edit attributes.
     * sets allows you to edit attrubutes for smartlight.
     */

    virtual void EditAttributes()override;
};

#endif // SMARTLIGHT_HPP
