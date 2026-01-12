#include "5424870_MD2_Task2_DTC.h"
#include <iostream>
using namespace std;

void displayAllDTCs(DTC** array, int size) {
    for (int i = 0; i < size; ++i) {
        if (array[i] != nullptr) {
            array[i]->printDTCInfo();
        }
    }
}

int main() {
    constexpr int N = 6;
    DTC* dtcArray[N] = {nullptr};

    DTC* dtcA = new DTC();
    DTC* dtcB = new DTC("P0301", "Cylinder 1 Misfire Detected", true, 5, 1000, CRIT, false, true, false, "Engine", "ECU_01");
    DTC* dtcC = new DTC(*dtcB);

    dtcA->setCode("P0001");
    dtcA->setDescription("Fuel Volume Regulator Control Circuit/Open");
    dtcA->setSystem("Fuel");
    dtcA->setOrigin("ECU_05");
    dtcA->setSeverity(WARN);
    dtcA->setOccurrenceCount(3);
    dtcA->setLastOccurrenceTime(500);
    dtcA->setMilOn(true);

    dtcB->incrementOccurrence();
    dtcB->toggleMIL();
    dtcC->markConfirmed();

    dtcArray[0] = dtcA;
    dtcArray[1] = dtcB;
    dtcArray[2] = nullptr;
    dtcArray[3] = dtcC;
    dtcArray[4] = new DTC("P0420", "Catalyst Efficiency Below Threshold", true, 2, 4000, WARN, false, false, true, "Exhaust", "ECU_02");
    dtcArray[5] = nullptr;

    cout << "\nRefactored Version Output:\n";
    displayAllDTCs(dtcArray, N);

    delete dtcArray[4];
    dtcArray[4] = nullptr;
    dtcArray[4] = new DTC("P0455", "Evaporative Emission System Leak Detected", true, 1, 5000, INFO, false, false, false, "EVAP", "ECU_03");

    cout << "\nAfter Modification:\n";
    displayAllDTCs(dtcArray, N);

    for (int i = 0; i < N; ++i) {
        delete dtcArray[i];
        dtcArray[i] = nullptr;
    }

    return 0;
}
