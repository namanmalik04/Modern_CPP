#ifndef DTC_H
#define DTC_H

#include <iostream>
#include <string>
using namespace std;

enum SeverityLevel { INFO, WARN, CRIT };

class DTC {
private:
    string m_code;
    string m_description;
    bool m_active;
    int m_occurrenceCount;
    long m_lastOccurrenceTime;
    SeverityLevel m_severity;
    bool m_confirmed;
    bool m_pending;
    bool m_milOn;
    string m_system;
    string m_origin;

public:
    // Delegating constructors
    DTC() : DTC("N/A", "Unknown", false, 0, 0, INFO, false, false, false, "Unknown", "Unknown") {}

    DTC(const string& code, const string& description, bool active, int occurrenceCount,
        long lastOccurrenceTime, SeverityLevel severity, bool confirmed, bool pending,
        bool milOn, const string& system, const string& origin)
        : m_code(code), m_description(description), m_active(active),
          m_occurrenceCount(occurrenceCount), m_lastOccurrenceTime(lastOccurrenceTime),
          m_severity(severity), m_confirmed(confirmed), m_pending(pending),
          m_milOn(milOn), m_system(system), m_origin(origin) {}

    DTC(const DTC& other)
        : DTC(other.m_code, other.m_description, other.m_active, other.m_occurrenceCount,
              other.m_lastOccurrenceTime, other.m_severity, other.m_confirmed,
              other.m_pending, other.m_milOn, other.m_system, other.m_origin) {}

    void printDTCInfo() const {
        cout << "---- DTC Information ----" << endl;
        cout << "Code: " << m_code << endl;
        cout << "Description: " << m_description << endl;
        cout << "Active: " << m_active << endl;
        cout << "Occurrences: " << m_occurrenceCount << endl;
        cout << "Last Time: " << m_lastOccurrenceTime << endl;
        cout << "Severity: " << m_severity << endl;
        cout << "Confirmed: " << m_confirmed << endl;
        cout << "Pending: " << m_pending << endl;
        cout << "MIL On: " << m_milOn << endl;
        cout << "System: " << m_system << endl;
        cout << "Origin: " << m_origin << endl;
        cout << "------------------------" << endl;
    }

    // Mutators
    void setCode(const string& code) { m_code = code; }
    void setDescription(const string& desc) { m_description = desc; }
    void setSeverity(SeverityLevel level) { m_severity = level; }
    void setOccurrenceCount(int count) { m_occurrenceCount = count; }
    void setLastOccurrenceTime(long time) { m_lastOccurrenceTime = time; }
    void setSystem(const string& sys) { m_system = sys; }
    void setOrigin(const string& org) { m_origin = org; }
    void setMilOn(bool status) { m_milOn = status; }

    // Methods
    void incrementOccurrence() { m_occurrenceCount++; }
    void toggleMIL() { m_milOn = !m_milOn; }
    void markConfirmed() { m_confirmed = true; }
};

#endif
