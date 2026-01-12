#include "5424870_MD1_Task1_Refactored_ClassDTC.h"
#include <memory>
using namespace std;

int main() {
    DTC** dtcArray = new DTC*[3];

    dtcArray[0] = new DTC("P0301", "Cylinder 1 Misfire Detected", true, 3, 1625247600, "Crit (2)",
                           true, false, true, "Engine", "ECU_01");
    dtcArray[1] = new DTC("P0420", "Catalyst Efficiency Below Threshold", false, 1, 1625248600, "Warn (1)",
                           false, true, false, "Exhaust", "ECU_02");
    dtcArray[2] = new DTC("P0171", "System Too Lean (Bank 1)", true, 2, 1625249600, "Info (0)",
                           true, false, true, "Fuel", "ECU_03");

    for (int i = 0; i < 3; ++i) {
        dtcArray[i]->toggleMIL();
        dtcArray[i]->updateOccurrenceCount(dtcArray[i]->isCritical() ? 5 : 2);
        dtcArray[i]->setActive(true);
        dtcArray[i]->printDTCInfo();
    }

    for (int i = 0; i < 3; ++i) {
        delete dtcArray[i];
    }
    delete[] dtcArray;

    return 0;
}
