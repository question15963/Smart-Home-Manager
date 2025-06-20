#ifndef SMARTSpeaker_HPP
#define SMARTSpeaker_HPP

#include "DeviceParent.hpp"

/** @brief Class for smart speaker.
 * Smart speaker atributes and methods
 */

class SmartSpeaker : public DeviceParent {
private:
    int mVolumeLevel; // Volume level of the smart speaker (0-100)

public:
    /*
     * @brief Constructor for SmartSpeaker
     * Initializes the smart speaker with the provided attributes.
     * @param id The unique ID of the device.
     * @param name The name of the device.
     * @param manufacturer The manufacturer of the device.
     * @param volumeLevel The volume level of the smart speaker.
     */

    SmartSpeaker(int id, const std::string& name, const std::string& manufacturer, int volumeLevel);

    /*
     * @brief Simulates user interaction with the smart speaker.
     * Allows the user to set the volume level.
     */

    void InteractionEvent() override;

    /**
     * @brief Displays detailed information about the smart speaker.
     * Outputs the device's ID, name, manufacturer, status, and volume level.
     */

    void ViewInfo() const override;

    /**
     * @brief Setter for volume level.
     * @sets the volume level
     */


    void SetVolumeLevel(int volume) { mVolumeLevel = volume; }
   
    
    /** @brief edit attributes.
     * sets allows you to edit attrubutes for smartspeaker.
     */

    void EditAttributes() override;
};

#endif // SMARTSpeaker_HPP
