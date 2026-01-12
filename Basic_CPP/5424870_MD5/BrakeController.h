#ifndef BRAKE_CONTROLLER_H
#define BRAKE_CONTROLLER_H

#include "Controller.h"

class BrakeController final : public Controller {
    double m_maxForce;

public:
    BrakeController(std::string name, double maxForce, TelemetryLevel level)
        : Controller(std::move(name), level), m_maxForce(maxForce) {}

    std::string operate(const TelemetryProvider* provider) const override {
        if (!provider)
            return "Brake:" + m_name + " FAIL NoTelemetry";

        return "Brake:" + m_name + " OK TelemetryFrom:" +
               provider->sourceName();
    }
};

#endif
