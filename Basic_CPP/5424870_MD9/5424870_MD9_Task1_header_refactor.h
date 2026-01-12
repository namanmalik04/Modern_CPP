#ifndef HEADER_5424870_MD9_TASK1_REFACTOR_H
#define HEADER_5424870_MD9_TASK1_REFACTOR_H

#include <iostream>
#include <iomanip>

class DetectedVehicleRefactor {
private:
    int m_id;
    float m_distanceMeters;
    float m_relativeSpeedMps;
    bool m_isBraking;

public:
    DetectedVehicleRefactor();
    DetectedVehicleRefactor(int id, float distanceMeters, float relativeSpeedMps, bool isBraking);

    int getId() const;
    float getDistanceMeters() const;
    float getRelativeSpeedMps() const;
    bool getIsBraking() const;

    void setId(int newId);
    void setDistanceMeters(float newDistance);
    void setRelativeSpeedMps(float newSpeed);
    void setIsBraking(bool braking);
};

float computeClosestDistanceRefactor(const DetectedVehicleRefactor arr[], int count);
int countBrakingVehiclesWithinRefactor(const DetectedVehicleRefactor arr[], int count, float maxDistance);

#endif
