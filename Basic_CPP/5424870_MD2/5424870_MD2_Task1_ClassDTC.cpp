#include "5424870_MD2_Task1_ClassDTC.h"

DTC::DTC(string code, string desc, bool active, int occCount, long lastTime, string severity,
         bool confirmed, bool pending, bool milOn, string system, string origin) {
    m_code = code;
    m_description = desc;
    m_active = active;
    m_occurrenceCount = occCount;
    m_lastTime = lastTime;
    m_severity = severity;
    m_confirmed = confirmed;
    m_pending = pending;
    m_milOn = milOn;
    m_system = system;
    m_origin = origin;
}

void DTC::printDTCInfo() {
    cout << "\nCode: " << m_code
         << "\nDescription: " << m_description
         << "\nActive: " << (m_active ? "true" : "false")
         << "\nOccurrence Count: " << m_occurrenceCount
         << "\nLast Time: " << m_lastTime
         << "\nSeverity: " << m_severity
         << "\nConfirmed: " << (m_confirmed ? "true" : "false")
         << "\nPending: " << (m_pending ? "true" : "false")
         << "\nMIL On: " << (m_milOn ? "true" : "false")
         << "\nSystem: " << m_system
         << "\nOrigin: " << m_origin << endl;
}

void DTC::setActive(bool active) {
    m_active = active;
}

void DTC::updateOccurrenceCount(int count) {
    m_occurrenceCount = count;
}

void DTC::toggleMIL() {
    m_milOn = !m_milOn;
}

bool DTC::isCritical() {
    return (m_severity.find("Crit") != string::npos);
}
