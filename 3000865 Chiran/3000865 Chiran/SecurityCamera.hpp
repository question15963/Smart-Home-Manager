#ifndef SECURITYCAMERA_H
#define SECURITYCAMERA_H

#include "DeviceParent.hpp"
#include <string>

/* @brief Class for securitycamera device.
 * methods and attributes for security camera dvice
 */

class SecurityCamera : public DeviceParent {
private:
    std::string mCameraQuality; // Quality of the camera (720p, 1080p, 4k)
    std::string mPower;         // Power source (mains, battery, solar)

public:

    /* @brief Constructor for SecurityCamera.
     * Initializes the security camera with the provided attributes.
     * @param id The unique ID of the device.
     * @param name The name of the device.
     * @param manufacturer The manufacturer of the device.
     * @param power The power source of the device.
     * @param cameraQuality The quality of the camera.
     */

    SecurityCamera(int id, const std::string& name, const std::string& manufacturer, const std::string& power, const std::string& cameraQuality);

    /*
     * @brief Simulates user interaction with the security camera.
     * Outputs a message indicating that the camera is being viewed.
     */

    void InteractionEvent() override;

    /* @brief Displays detailed information about the security camera
     * Outputs the device's ID, name, manufacturer, status, power source, and camera quality.
     */

    void ViewInfo() const override;

    /*
    * @brief setters for eedit securitycamera
    */

    void SetCameraQuality(const std::string& quality) { mCameraQuality = quality; }
    void SetPowerSource(const std::string& power) { mPower = power; }

    /** @brief edit attributes.
     * sets allows you to edit attrubutes for securitycamera.
     */
    void EditAttributes()override;

};

#endif // SECURITYCAMERA_H
