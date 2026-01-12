#include <iostream>
#include "AutomotiveSubsystem.h"
#include "MotorController.h"
#include "BrakeController.h"
#include "Telemetry.h"

int main() {
    TelemetryProvider tp1("SRC_BAS_Unit1");
    TelemetryProvider tp2("SRC_EXT_Unit2");

    AutomotiveSubsystem sub;
    sub.addTelemetryProvider(&tp1);
    sub.addTelemetryProvider(&tp2);

    sub.addController(std::make_unique<MotorController>("M1", 7000));
    sub.addController(std::make_unique<BrakeController>("B1", 1200.0, TelemetryLevel::EXTENDED));

    for (const auto& res : sub.runAll())
        std::cout << res << '\n';

    return 0;
}
