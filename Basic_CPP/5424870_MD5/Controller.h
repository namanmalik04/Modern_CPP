#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "Telemetry.h"
#include <string>

class Controller {
protected:
    std::string m_name;
    TelemetryLevel m_level;

public:
    Controller() = delete;
    Controller(std::string name, TelemetryLevel level)
        : m_name(std::move(name)), m_level(level) {}
    virtual ~Controller() = default;

    virtual std::string operate(const TelemetryProvider* provider) const = 0;
    TelemetryLevel telemetryLevel() const { return m_level; }
};

#endif
