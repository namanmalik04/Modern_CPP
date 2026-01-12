#ifndef DTC_H
#define DTC_H

#include <iostream>
#include <string>

class DTC {
private:
    std::string m_code;
    std::string m_description;
    bool m_active;
    int m_occurrenceCount;
    long m_lastTime;
    std::string m_severity;
    bool m_confirmed;
    bool m_pending;
    bool m_milOn;
    std::string m_system;
    std::string m_origin;

public:
    DTC(const std::string& code, const std::string& desc, bool active, int occCount, long lastTime,
        const std::string& severity, bool confirmed, bool pending, bool milOn,
        const std::string& system, const std::string& origin);

    void printDTCInfo() const;
    void setActive(bool active);
    void updateOccurrenceCount(int count);
    void toggleMIL();
    bool isCritical() const;
};

#endif
