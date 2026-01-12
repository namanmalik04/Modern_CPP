#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

/**
 * @brief Enum representing diagnostic severity.
 */
enum SeverityLevel { INFO = 0, WARN = 1, CRIT = 2 };

/**
 * @brief Represents a Diagnostic Trouble Code (DTC) including risk and recommendations.
 */
class DTC {
private:
    string code;
    string description;
    bool active;
    int occurrenceCount;
    SeverityLevel severityLevel;
    double riskScore;
    string recommendedAction;

public:
    // ---------- Constructors ----------
    DTC()
        : code(""), description(""), active(false), occurrenceCount(0),
          severityLevel(INFO), riskScore(0.0), recommendedAction("") {}

    DTC(const string& c, const string& d, bool a, int count, SeverityLevel s)
        : code(c), description(d), active(a), occurrenceCount(count),
          severityLevel(s), riskScore(0.0), recommendedAction("") {}

    // ---------- Behavior Methods ----------
    void calculateRisk() {
        switch (severityLevel) {
            case CRIT: riskScore = 0.9; break;
            case WARN: riskScore = 0.6; break;
            default:   riskScore = 0.3; break;
        }
    }

    void suggestAction() {
        switch (severityLevel) {
            case CRIT:
                recommendedAction = "Stop vehicle and inspect immediately.";
                break;
            case WARN:
                recommendedAction = "Service soon.";
                break;
            default:
                recommendedAction = "Monitor system.";
                break;
        }
    }

    static DTC merge(const DTC& dtc1, const DTC& dtc2) {
        DTC merged;
        merged.code = dtc1.code + "/" + dtc2.code;
        merged.description = dtc1.description + " & " + dtc2.description;
        merged.active = dtc1.active || dtc2.active;
        merged.occurrenceCount = dtc1.occurrenceCount + dtc2.occurrenceCount;
        merged.severityLevel = static_cast<SeverityLevel>(
            max(dtc1.severityLevel, dtc2.severityLevel));
        merged.calculateRisk();
        merged.suggestAction();
        return merged;
    }

    void display() const {
        cout << "\n==============================";
        cout << "\nDTC Code           : " << code;
        cout << "\nDescription        : " << description;
        cout << "\nActive             : " << (active ? "Yes" : "No");
        cout << "\nOccurrences        : " << occurrenceCount;
        cout << "\nSeverity Level     : " << severityLevel;
        cout << "\nRisk Score         : " << riskScore;
        cout << "\nRecommended Action : " << recommendedAction;
        cout << "\n==============================\n";
    }
};

// ---------- Main ----------
int main() {
    DTC dtcA("P0301", "Cylinder Misfire", true, 2, CRIT);
    DTC dtcB("P0420", "Catalyst Efficiency Low", false, 1, WARN);

    dtcA.calculateRisk();
    dtcB.calculateRisk();
    dtcA.suggestAction();
    dtcB.suggestAction();

    DTC mergedDTC = DTC::merge(dtcA, dtcB);

    cout << "\n--- DTC 1 ---";
    dtcA.display();

    cout << "\n--- DTC 2 ---";
    dtcB.display();

    cout << "\n--- Merged DTC ---";
    mergedDTC.display();

    return 0;
}
