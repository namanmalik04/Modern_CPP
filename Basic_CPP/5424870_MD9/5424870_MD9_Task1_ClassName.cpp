#include "5424870_MD9_Task1_header.h"

// Default constructor
DetectedVehicle::DetectedVehicle()
    : m_id(-1), m_distanceMeters(0.0f), m_relativeSpeedMps(0.0f), m_isBraking(false) {}

// Parameterized constructor
DetectedVehicle::DetectedVehicle(int id, float distanceMeters, float relativeSpeedMps, bool isBraking) {
    setId(id);
    setDistanceMeters(distanceMeters);
    setRelativeSpeedMps(relativeSpeedMps);
    setIsBraking(isBraking);
}

// Getters
int DetectedVehicle::getId() const { return m_id; }
float DetectedVehicle::getDistanceMeters() const { return m_distanceMeters; }
float DetectedVehicle::getRelativeSpeedMps() const { return m_relativeSpeedMps; }
bool DetectedVehicle::getIsBraking() const { return m_isBraking; }

// Setters
void DetectedVehicle::setId(int newId) {
    if (newId >= 0)
        m_id = newId;
    else
        m_id = -1;
}

void DetectedVehicle::setDistanceMeters(float newDistance) {
    m_distanceMeters = (newDistance < 0.0f) ? 0.0f : newDistance;
}

void DetectedVehicle::setRelativeSpeedMps(float newSpeed) {
    m_relativeSpeedMps = newSpeed;
}

void DetectedVehicle::setIsBraking(bool braking) {
    m_isBraking = braking;
}

// Global functions
float computeClosestDistance(const DetectedVehicle arr[], int count) {
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

int countBrakingVehiclesWithin(const DetectedVehicle arr[], int count, float maxDistance) {
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
