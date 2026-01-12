#include <iostream>
#include <string>
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
    // ---------- Constructor ----------
    DTC()
        : code(""), description(""), active(false),
          occurrenceCount(0), severityLevel(INFO), milOn(false) {}

    // ---------- Setters ----------
    void setCode(const string& c) { code = c; }
    void setDescription(const string& d) { description = d; }
    void setActive(bool a) { active = a; }
    void setOccurrenceCount(int count) { occurrenceCount = count; }
    void setSeverityLevel(SeverityLevel s) { severityLevel = s; }
    void setMilOn(bool m) { milOn = m; }

    // ---------- Methods ----------
    void incrementOccurrence() { ++occurrenceCount; }
    void toggleMIL() { milOn = !milOn; }
    void printDTCInfo() const {
        cout << "\n--- DTC Info ---";
        cout << "\nCode        : " << code;
        cout << "\nDescription : " << description;
        cout << "\nActive      : " << (active ? "Yes" : "No");
        cout << "\nOccurrences : " << occurrenceCount;
        cout << "\nSeverity    : " << severityLevel;
        cout << "\nMIL On      : " << (milOn ? "Yes" : "No");
        cout << "\n----------------\n";
    }
};

// ---------- Demonstrations ----------

// Memory leak demonstration
void leakDemo() {
    DTC* dtc1 = new DTC();
    DTC* dtc2 = new DTC(); // Memory leak intentional
    dtc1->setCode("P0301");
    dtc1->incrementOccurrence();
    delete dtc1;
    // dtc2 is never deleted → demonstrates memory leak
}

// Fixed memory leak
void leakFix() {
    DTC* dtc1 = new DTC();
    DTC* dtc2 = new DTC();
    dtc1->setCode("P0301");
    dtc2->setCode("P0420");
    delete dtc1;
    dtc1 = nullptr;
    delete dtc2;
    dtc2 = nullptr; // Memory safely freed
}

// Dangling pointer demonstration
void danglingDemo() {
    DTC* dtc = new DTC();
    dtc->setCode("P0171");
    delete dtc;
    // dtc->printDTCInfo(); // Unsafe, causes dangling pointer
}

// Safe dangling pointer fix
void danglingFix() {
    DTC* dtc = new DTC();
    dtc->setCode("P0171");
    delete dtc;
    dtc = nullptr; // Nulling prevents dangling pointer
    if (dtc) dtc->printDTCInfo(); // Safe access check
}
    
int main() {
    // Dynamic allocation example
    DTC* dynamicDTC = new DTC();
    dynamicDTC->setCode("P0302");
    dynamicDTC->incrementOccurrence();
    dynamicDTC->toggleMIL();
    dynamicDTC->printDTCInfo();
    delete dynamicDTC;
    dynamicDTC = nullptr; // Prevent dangling pointer

    // Demonstrations
    leakDemo();
    leakFix();
    danglingDemo();
    danglingFix();

    return 0;
}
