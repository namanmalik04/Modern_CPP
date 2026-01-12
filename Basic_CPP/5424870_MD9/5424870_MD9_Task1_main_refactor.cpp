#include "5424870_MD9_Task1_header_refactor.h"

int main() {
    DetectedVehicleRefactor vehicles[10];

    vehicles[0] = DetectedVehicleRefactor(0, 12.5f, -2.0f, false);
    vehicles[1] = DetectedVehicleRefactor(1, 8.0f, 1.5f, true);
    vehicles[2] = DetectedVehicleRefactor(2, 20.0f, 0.0f, false);

    std::cout << std::fixed << std::setprecision(1)
              << computeClosestDistanceRefactor(vehicles, 10) << "\n";
    std::cout << countBrakingVehiclesWithinRefactor(vehicles, 10, 10.0f) << "\n";

    return 0;
}
