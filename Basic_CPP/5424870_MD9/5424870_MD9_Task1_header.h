#ifndef HEADER_5424870_MD9_TASK1_H
#define HEADER_5424870_MD9_TASK1_H

#include <iostream>
#include <iomanip>
#include <algorithm>

class DetectedVehicle {
private:
    int m_id;
    float m_distanceMeters;
    float m_relativeSpeedMps;
    bool m_isBraking;

public:
    // Default constructor
    DetectedVehicle();

    // Parameterized constructor
    DetectedVehicle(int id, float distanceMeters, float relativeSpeedMps, bool isBraking);

    // Getters
    int getId() const;
    float getDistanceMeters() const;
    float getRelativeSpeedMps() const;
    bool getIsBraking() const;

    // Setters
    void setId(int newId);
    void setDistanceMeters(float newDistance);
    void setRelativeSpeedMps(float newSpeed);
    void setIsBraking(bool braking);
};

// Global functions
float computeClosestDistance(const DetectedVehicle arr[], int count);
int countBrakingVehiclesWithin(const DetectedVehicle arr[], int count, float maxDistance);

#endif
