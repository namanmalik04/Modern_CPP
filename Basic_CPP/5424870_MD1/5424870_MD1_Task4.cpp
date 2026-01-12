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
    SeverityLevel severityLevel;
    bool milOn;

public:
    DTC() : code(""), description(""), active(false),
            occurrenceCount(0), severityLevel(INFO), milOn(false) {}

    // Setters
    void setCode(const string& c) { code = c; }
    void setDescription(const string& d) { description = d; }
    void setActive(bool a) { active = a; }
    void setOccurrenceCount(int count) { occurrenceCount = count; }
    void setSeverityLevel(SeverityLevel s) { severityLevel = s; }
    void setMilOn(bool m) { milOn = m; }

    // Methods
    void incrementOccurrence() { occurrenceCount++; }
    void toggleMIL() { milOn = !milOn; }
    void printDTCInfo() {
        cout << "\nCode: " << code;
        cout << "\nDescription: " << description;
        cout << "\nActive: " << (active ? "Yes" : "No");
        cout << "\nOccurrences: " << occurrenceCount;
        cout << "\nSeverity: " << severityLevel;
        cout << "\nMIL On: " << (milOn ? "Yes" : "No") << endl;
    }
};

// Function to demonstrate memory leak
void leakDemo() {
    DTC* dtc1 = new DTC();
    DTC* dtc2 = new DTC(); // This will leak
    dtc1->setCode("P0301");
    dtc1->incrementOccurrence();
    delete dtc1;
    // dtc2 is never deleted → memory leak
}

// Function to fix memory leak
void leakFix() {
    DTC* dtc1 = new DTC();
    DTC* dtc2 = new DTC();
    dtc1->setCode("P0301");
    dtc2->setCode("P0420");
    delete dtc1;
    dtc1 = nullptr;
    delete dtc2;
    dtc2 = nullptr;
}

// Dangling pointer demo
void danglingDemo() {
    DTC* dtc = new DTC();
    dtc->setCode("P0171");
    delete dtc;
    // dtc->printDTCInfo(); // Unsafe → dangling pointer
}

// Safe dangling pointer fix
void danglingFix() {
    DTC* dtc = new DTC();
    dtc->setCode("P0171");
    delete dtc;
    dtc = nullptr;
    if (dtc) dtc->printDTCInfo(); // Safe
}

int main() {
    // Dynamic allocation
    DTC* dynamicDTC = new DTC();
    dynamicDTC->setCode("P0302");
    dynamicDTC->incrementOccurrence();
    dynamicDTC->toggleMIL();
    //dynamicDTC->printDTCInfo();
    delete dynamicDTC;
    dynamicDTC = nullptr; // Avoid dangling pointer

    leakDemo();
    leakFix();
    danglingDemo();
    danglingFix();

    return 0;
}
