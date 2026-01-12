#ifndef DTC_H
#define DTC_H

#include <iostream>
#include <string>
using namespace std;

class DTC {
private:
    string m_code;
    string m_description;
    bool m_active;
    int m_occurrenceCount;
    long m_lastTime;
    string m_severity;
    bool m_confirmed;
    bool m_pending;
    bool m_milOn;
    string m_system;
    string m_origin;

public:
    DTC(string code, string desc, bool active, int occCount, long lastTime, string severity,
        bool confirmed, bool pending, bool milOn, string system, string origin);

    void printDTCInfo();
    void setActive(bool active);
    void updateOccurrenceCount(int count);
    void toggleMIL();
    bool isCritical();
};

#endif
