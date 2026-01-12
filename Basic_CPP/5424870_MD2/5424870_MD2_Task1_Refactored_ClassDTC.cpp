#include "5424870_MD1_Task1_Refactored_ClassDTC.h"
using namespace std;

DTC::DTC(const string& code, const string& desc, bool active, int occCount, long lastTime,
         const string& severity, bool confirmed, bool pending, bool milOn,
         const string& system, const string& origin)
    : m_code(code), m_description(desc), m_active(active), m_occurrenceCount(occCount),
      m_lastTime(lastTime), m_severity(severity), m_confirmed(confirmed),
      m_pending(pending), m_milOn(milOn), m_system(system), m_origin(origin) {}

void DTC::printDTCInfo() const {
    cout << "\n---- DTC Information ----"
         << "\nCode: " << m_code
         << "\nDescription: " << m_description
         << "\nActive: " << (m_active ? "true" : "false")
         << "\nOccurrences: " << m_occurrenceCount
         << "\nLast Time: " << m_lastTime
         << "\nSeverity: " << m_severity
         << "\nConfirmed: " << (m_confirmed ? "true" : "false")
         << "\nPending: " << (m_pending ? "true" : "false")
         << "\nMIL On: " << (m_milOn ? "true" : "false")
         << "\nSystem: " << m_system
         << "\nOrigin: " << m_origin
         << "\n------------------------\n";
}

void DTC::setActive(bool active) { m_active = active; }

void DTC::updateOccurrenceCount(int count) {
    if (count >= 0) {
        m_occurrenceCount = count;
    }
}

void DTC::toggleMIL() { m_milOn = !m_milOn; }

bool DTC::isCritical() const { return m_severity.find("Crit") != string::npos; }
