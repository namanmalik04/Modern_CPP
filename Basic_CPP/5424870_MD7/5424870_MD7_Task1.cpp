#include <iostream>
#include <string>
#include <ctime>
using namespace std;

enum SeverityLevel { INFO = 0, WARN = 1, CRIT = 2 };

class DTC {
private:
    string code;
    string description;
    bool active;
    int occurrenceCount;
    time_t lastOccurrenceTime;
    SeverityLevel severityLevel;
    bool confirmed;
    bool pending;
    bool milOn;

public:
    DTC() {
        code = "";
        description = "";
        active = false;
        occurrenceCount = 0;
        lastOccurrenceTime = 0;
        severityLevel = INFO;
        confirmed = false;
        pending = false;
        milOn = false;
    }

    DTC(string c, string d, bool a, int count, time_t time,
        SeverityLevel s, bool conf, bool pend, bool mil) {
        code = c;
        description = d;
        active = a;
        occurrenceCount = count;
        lastOccurrenceTime = time;
        severityLevel = s;
        confirmed = conf;
        pending = pend;
        milOn = mil;
    }

    DTC(const DTC &other) {
        code = other.code;
        description = other.description;
        active = other.active;
        occurrenceCount = other.occurrenceCount;
        lastOccurrenceTime = other.lastOccurrenceTime;
        severityLevel = other.severityLevel;
        confirmed = other.confirmed;
        pending = other.pending;
        milOn = other.milOn;
    }

    // getters and setters
    string getCode() { return code; }
    string getDescription() { return description; }
    bool getActive() { return active; }
    int getOccurrenceCount() { return occurrenceCount; }
    time_t getLastOccurrenceTime() { return lastOccurrenceTime; }
    SeverityLevel getSeverityLevel() { return severityLevel; }
    bool getConfirmed() { return confirmed; }
    bool getPending() { return pending; }
    bool getMilOn() { return milOn; }

    void setCode(string c) { code = c; }
    void setDescription(string d) { description = d; }
    void setActive(bool a) { active = a; }
    void setOccurrenceCount(int c) { occurrenceCount = c; }
    void setLastOccurrenceTime(time_t t) { lastOccurrenceTime = t; }
    void setSeverityLevel(SeverityLevel s) { severityLevel = s; }
    void setConfirmed(bool c) { confirmed = c; }
    void setPending(bool p) { pending = p; }
    void setMilOn(bool m) { milOn = m; }

    void activate() { active = true; }
    void deactivate() { active = false; }
    void incrementOccurrence() { occurrenceCount++; }

    void toggleMIL() { milOn = !milOn; }

    void markConfirmed() {
        confirmed = true;
        pending = false;
    }

    void printDTCInfo() {
        cout << "\nDTC Code: " << code;
        cout << "\nDescription: " << description;
        cout << "\nActive: " << (active ? "Yes" : "No");
        cout << "\nOccurrence Count: " << occurrenceCount;
        cout << "\nLast Occurrence Time: " << lastOccurrenceTime;
        cout << "\nSeverity Level: " << severityLevel;
        cout << "\nConfirmed: " << (confirmed ? "Yes" : "No");
        cout << "\nPending: " << (pending ? "Yes" : "No");
        cout << "\nMIL On: " << (milOn ? "Yes" : "No") << endl;
    }
};

int main() {
    DTC dtc1;
    DTC dtc2("P0301", "Cylinder 1 Misfire Detected", true, 3, time(0),
             CRIT, true, false, true);

    dtc1.setCode("P0420");
    dtc1.setDescription("Catalyst System Efficiency Below Threshold");
    dtc1.setOccurrenceCount(2);
    dtc1.setSeverityLevel(WARN);
    dtc1.setActive(true);
    dtc1.setMilOn(false);

    dtc1.incrementOccurrence();
    dtc2.incrementOccurrence();

    dtc1.toggleMIL();
    dtc2.markConfirmed();

    dtc1.printDTCInfo();
    dtc2.printDTCInfo();

    return 0;
}
