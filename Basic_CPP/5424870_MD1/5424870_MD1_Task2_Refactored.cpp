#include <iostream>
#include <string>
#include <ctime>
using namespace std;

/**
 * @brief Enum representing severity levels of diagnostic trouble codes.
 */
enum SeverityLevel { INFO = 0, WARN = 1, CRIT = 2 };

/**
 * @brief Represents a Diagnostic Trouble Code (DTC) in a vehicle system.
 */
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
    // ---------------- Constructors ----------------
    DTC()
        : code(""), description(""), active(false), occurrenceCount(0),
          lastOccurrenceTime(0), severityLevel(INFO),
          confirmed(false), pending(false), milOn(false) {}

    DTC(const string& c, const string& d, bool a, int count, time_t time,
        SeverityLevel s, bool conf, bool pend, bool mil)
        : code(c), description(d), active(a), occurrenceCount(count),
          lastOccurrenceTime(time), severityLevel(s),
          confirmed(conf), pending(pend), milOn(mil) {}

    // Copy constructor
    DTC(const DTC& other)
        : code(other.code), description(other.description),
          active(other.active), occurrenceCount(other.occurrenceCount),
          lastOccurrenceTime(other.lastOccurrenceTime),
          severityLevel(other.severityLevel),
          confirmed(other.confirmed), pending(other.pending),
          milOn(other.milOn) {}

    // ---------------- Getters & Setters ----------------
    string getCode() const { return code; }
    string getDescription() const { return description; }
    bool isActive() const { return active; }
    int getOccurrenceCount() const { return occurrenceCount; }
    time_t getLastOccurrenceTime() const { return lastOccurrenceTime; }
    SeverityLevel getSeverityLevel() const { return severityLevel; }
    bool isConfirmed() const { return confirmed; }
    bool isPending() const { return pending; }
    bool isMilOn() const { return milOn; }

    void setCode(const string& c) { code = c; }
    void setDescription(const string& d) { description = d; }
    void setActive(bool a) { active = a; }
    void setOccurrenceCount(int count) { occurrenceCount = count; }
    void setLastOccurrenceTime(time_t t) { lastOccurrenceTime = t; }
    void setSeverityLevel(SeverityLevel s) { severityLevel = s; }
    void setConfirmed(bool c) { confirmed = c; }
    void setPending(bool p) { pending = p; }
    void setMilOn(bool m) { milOn = m; }

    // ---------------- Behavior Methods ----------------
    void activate() { active = true; }
    void deactivate() { active = false; }
    void incrementOccurrence() { ++occurrenceCount; }
    void toggleMIL() { milOn = !milOn; }

    void markConfirmed() {
        confirmed = true;
        pending = false;
    }

    void printDTCInfo() const {
        cout << "\n=== Diagnostic Trouble Code Details ===" << endl;
        cout << "Code              : " << code << endl;
        cout << "Description       : " << description << endl;
        cout << "Active            : " << (active ? "Yes" : "No") << endl;
        cout << "Occurrence Count  : " << occurrenceCount << endl;
        cout << "Last Occurrence   : " << lastOccurrenceTime << endl;
        cout << "Severity Level    : " << severityLevel << endl;
        cout << "Confirmed         : " << (confirmed ? "Yes" : "No") << endl;
        cout << "Pending           : " << (pending ? "Yes" : "No") << endl;
        cout << "MIL On            : " << (milOn ? "Yes" : "No") << endl;
        cout << "======================================" << endl;
    }
};

// ---------------- Main ----------------
int main() {
    // Default constructor object
    DTC dtcDefault;

    // Parameterized constructor object
    DTC dtcParam("P0301", "Cylinder 1 Misfire Detected", true, 3, time(nullptr),
                 CRIT, true, false, true);

    // Modify dtcDefault attributes via setters
    dtcDefault.setCode("P0420");
    dtcDefault.setDescription("Catalyst System Efficiency Below Threshold");
    dtcDefault.setOccurrenceCount(2);
    dtcDefault.setSeverityLevel(WARN);
    dtcDefault.setActive(true);
    dtcDefault.setMilOn(false);

    // Increment occurrences and update statuses
    dtcDefault.incrementOccurrence();
    dtcParam.incrementOccurrence();

    dtcDefault.toggleMIL();
    dtcParam.markConfirmed();

    // Display details
    cout << "\n--- DTC Object 1 ---";
    dtcDefault.printDTCInfo();

    cout << "\n--- DTC Object 2 ---";
    dtcParam.printDTCInfo();

    return 0;
}
