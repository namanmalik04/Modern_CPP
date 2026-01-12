#include <iostream>
#include <string>
using namespace std;

enum SeverityLevel { INFO = 0, WARN = 1, CRIT = 2 };

class DTC {
public:
    string code;
    string description;
    bool active;
    int occurrenceCount;
    SeverityLevel severityLevel;
    double riskScore;
    string recommendedAction;

    DTC() {
        code = "";
        description = "";
        active = false;
        occurrenceCount = 0;
        severityLevel = INFO;
        riskScore = 0.0;
        recommendedAction = "";
    }

    DTC(string c, string d, bool a, int count, SeverityLevel s) {
        code = c;
        description = d;
        active = a;
        occurrenceCount = count;
        severityLevel = s;
        riskScore = 0.0;
        recommendedAction = "";
    }

    void calculateRisk() {
        if (severityLevel == CRIT)
            riskScore = 0.9;
        else if (severityLevel == WARN)
            riskScore = 0.6;
        else
            riskScore = 0.3;
    }

    void suggestAction() {
        if (severityLevel == CRIT)
            recommendedAction = "Stop vehicle and inspect immediately.";
        else if (severityLevel == WARN)
            recommendedAction = "Service soon.";
        else
            recommendedAction = "Monitor system.";
    }

    static DTC merge(DTC d1, DTC d2) {
        DTC merged;
        merged.code = d1.code + "/" + d2.code;
        merged.description = d1.description + " & " + d2.description;
        merged.active = d1.active || d2.active;
        merged.occurrenceCount = d1.occurrenceCount + d2.occurrenceCount;
        merged.severityLevel = (d1.severityLevel > d2.severityLevel) ? d1.severityLevel : d2.severityLevel;
        merged.calculateRisk();
        merged.suggestAction();
        return merged;
    }

    void display() {
        cout << "\nCode: " << code;
        cout << "\nDescription: " << description;
        cout << "\nActive: " << (active ? "Yes" : "No");
        cout << "\nOccurrence Count: " << occurrenceCount;
        cout << "\nSeverity: " << severityLevel;
        cout << "\nRisk Score: " << riskScore;
        cout << "\nRecommended Action: " << recommendedAction << endl;
    }
};

int main() {
    DTC d1("P0301", "Cylinder Misfire", true, 2, CRIT);
    DTC d2("P0420", "Catalyst Efficiency Low", false, 1, WARN);

    d1.calculateRisk();
    d2.calculateRisk();
    d1.suggestAction();
    d2.suggestAction();

    DTC merged = DTC::merge(d1, d2);

    cout << "\n--- DTC 1 ---";
    d1.display();
    cout << "\n--- DTC 2 ---";
    d2.display();
    cout << "\n--- Merged DTC ---";
    merged.display();

    return 0;
}
