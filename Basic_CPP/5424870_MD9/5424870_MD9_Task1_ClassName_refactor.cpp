#include "5424870_MD9_Task1_header_refactor.h"

DetectedVehicleRefactor::DetectedVehicleRefactor()
    : m_id(-1), m_distanceMeters(0.0f), m_relativeSpeedMps(0.0f), m_isBraking(false) {}

DetectedVehicleRefactor::DetectedVehicleRefactor(int id, float distanceMeters, float relativeSpeedMps, bool isBraking) {
    setId(id);
    setDistanceMeters(distanceMeters);
    setRelativeSpeedMps(relativeSpeedMps);
    setIsBraking(isBraking);
}

int DetectedVehicleRefactor::getId() const { return m_id; }
float DetectedVehicleRefactor::getDistanceMeters() const { return m_distanceMeters; }
float DetectedVehicleRefactor::getRelativeSpeedMps() const { return m_relativeSpeedMps; }
bool DetectedVehicleRefactor::getIsBraking() const { return m_isBraking; }

void DetectedVehicleRefactor::setId(int newId) {
    m_id = (newId >= 0) ? newId : -1;
}

void DetectedVehicleRefactor::setDistanceMeters(float newDistance) {
    m_distanceMeters = (newDistance < 0.0f) ? 0.0f : newDistance;
}

void DetectedVehicleRefactor::setRelativeSpeedMps(float newSpeed) {
    m_relativeSpeedMps = newSpeed;
}

void DetectedVehicleRefactor::setIsBraking(bool braking) {
    m_isBraking = braking;
}

float computeClosestDistanceRefactor(const DetectedVehicleRefactor arr[], int count) {
    float minDist = -1.0f;
    for (int i = 0; i < count; ++i) {
        if (arr[i].getId() >= 0) {
            float d = arr[i].getDistanceMeters();
            if (minDist < 0.0f || d < minDist)
                minDist = d;
        }
    }
    return minDist;
}

int countBrakingVehiclesWithinRefactor(const DetectedVehicleRefactor arr[], int count, float maxDistance) {
    int brakingCount = 0;
    for (int i = 0; i < count; ++i) {
        if (arr[i].getId() >= 0 &&
            arr[i].getIsBraking() &&
            arr[i].getDistanceMeters() <= maxDistance) {
            ++brakingCount;
        }
    }
    return brakingCount;
}
