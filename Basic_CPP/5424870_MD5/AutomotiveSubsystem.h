#ifndef AUTOMOTIVE_SUBSYSTEM_H
#define AUTOMOTIVE_SUBSYSTEM_H

#include "Controller.h"
#include <memory>
#include <vector>

class AutomotiveSubsystem {
    std::vector<std::unique_ptr<Controller>> m_controllers;
    std::vector<const TelemetryProvider*> m_providers;

public:
    AutomotiveSubsystem() = default;
    AutomotiveSubsystem(const AutomotiveSubsystem&) = delete;
    AutomotiveSubsystem& operator=(const AutomotiveSubsystem&) = delete;
    AutomotiveSubsystem(AutomotiveSubsystem&&) = default;
    AutomotiveSubsystem& operator=(AutomotiveSubsystem&&) = default;

    void addController(std::unique_ptr<Controller> ctrl) {
        if (ctrl)
            m_controllers.push_back(std::move(ctrl));
    }

    void addTelemetryProvider(const TelemetryProvider* provider) {
        if (provider)
            m_providers.push_back(provider);
    }

    std::vector<std::string> runAll() const {
        std::vector<std::string> results;

        for (const auto& ctrl : m_controllers) {
            const TelemetryProvider* selected = nullptr;

            for (auto* tp : m_providers) {
                const std::string& src = tp->sourceName();

                if (src.find("BAS") != std::string::npos &&
                    hasLevel(ctrl->telemetryLevel(), TelemetryLevel::BASIC)) {
                    selected = tp;
                    break;
                }
                if (src.find("EXT") != std::string::npos &&
                    hasLevel(ctrl->telemetryLevel(), TelemetryLevel::EXTENDED)) {
                    selected = tp;
                    break;
                }
            }

            results.push_back(ctrl->operate(selected));
        }
        return results;
    }
};

#endif
