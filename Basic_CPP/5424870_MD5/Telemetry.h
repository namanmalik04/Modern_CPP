#ifndef TELEMETRY_H
#define TELEMETRY_H

#include <string>

enum class TelemetryLevel {
    NONE = 0,
    BASIC = 1,
    EXTENDED = 2
};

inline TelemetryLevel operator|(TelemetryLevel a, TelemetryLevel b) {
    return static_cast<TelemetryLevel>(
        static_cast<int>(a) | static_cast<int>(b)
    );
}

inline bool hasLevel(TelemetryLevel mask, TelemetryLevel flag) {
    return (static_cast<int>(mask) & static_cast<int>(flag)) != 0;
}

class TelemetryProvider {
    std::string m_source;

public:
    explicit TelemetryProvider(std::string source)
        : m_source(std::move(source)) {}

    TelemetryProvider(const TelemetryProvider&) = delete;
    TelemetryProvider& operator=(const TelemetryProvider&) = delete;
    TelemetryProvider(TelemetryProvider&&) = default;
    TelemetryProvider& operator=(TelemetryProvider&&) = default;

    std::string sourceName() const { return m_source; }
};

#endif
