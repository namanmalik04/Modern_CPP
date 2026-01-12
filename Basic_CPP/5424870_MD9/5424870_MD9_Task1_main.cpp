#include "5424870_MD9_Task1_header.h"

int main() {
    DetectedVehicle vehicles[10];

    // Test Case 1
    vehicles[0] = DetectedVehicle(0, 12.5f, -2.0f, false);
    vehicles[1] = DetectedVehicle(1, 8.0f, 1.5f, true);
    vehicles[2] = DetectedVehicle(2, 20.0f, 0.0f, false);

    std::cout << std::fixed << std::setprecision(1)
              << computeClosestDistance(vehicles, 10) << "\n";
    std::cout << countBrakingVehiclesWithin(vehicles, 10, 10.0f) << "\n";

    return 0;
}
