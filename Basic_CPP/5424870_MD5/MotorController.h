#ifndef MOTOR_CONTROLLER_H
#define MOTOR_CONTROLLER_H

#include "Controller.h"

class MotorController final : public Controller {
    int m_rpmLimit;

public:
    MotorController(std::string name, int rpmLimit)
        : MotorController(std::move(name), rpmLimit, TelemetryLevel::BASIC) {}

    MotorController(std::string name, int rpmLimit, TelemetryLevel level)
        : Controller(std::move(name), level), m_rpmLimit(rpmLimit) {}

    std::string operate(const TelemetryProvider* provider) const override {
        if (!provider)
            return "Motor:" + m_name + " Running RPMLimit:" +
                   std::to_string(m_rpmLimit) + " NoTelemetry";

        const std::string& src = provider->sourceName();

        if (src.find("BAS") != std::string::npos &&
            hasLevel(m_level, TelemetryLevel::BASIC))
            return "Motor:" + m_name + " Running RPMLimit:" +
                   std::to_string(m_rpmLimit) + " TelemetryFrom:" + src;

        if (src.find("EXT") != std::string::npos &&
            hasLevel(m_level, TelemetryLevel::EXTENDED))
            return "Motor:" + m_name + " Running RPMLimit:" +
                   std::to_string(m_rpmLimit) + " TelemetryFrom:" + src;

        return "Motor:" + m_name + " Running RPMLimit:" +
               std::to_string(m_rpmLimit) + " NoTelemetry";
    }
};

#endif
