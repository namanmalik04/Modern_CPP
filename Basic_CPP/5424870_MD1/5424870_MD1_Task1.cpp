#include <iostream>
#include <string>
using namespace std;

class FleetVehicle {
private:
    int vehicleID;
    float fuelLevel;
    double distanceTravelled;
    char status;
    bool isAvailable;
    string driverName;

public:
    FleetVehicle() {
        vehicleID = 0;
        fuelLevel = 50.0;
        distanceTravelled = 0.0;
        status = 'A';
        isAvailable = true;
        driverName = "Unassigned";
    }

    FleetVehicle(int id, float fuel, double dist, char st, bool avail, string name) {
        vehicleID = id;
        fuelLevel = fuel;
        distanceTravelled = dist;
        status = st;
        isAvailable = avail;
        driverName = name;
    }

    ~FleetVehicle() {
        cout << "Destructor called for vehicle ID: " << vehicleID << endl;
    }

    // Getters and Setters
    int getVehicleID() { return vehicleID; }
    float getFuelLevel() { return fuelLevel; }
    double getDistanceTravelled() { return distanceTravelled; }
    char getStatus() { return status; }
    bool getIsAvailable() { return isAvailable; }
    string getDriverName() { return driverName; }

    void setVehicleID(int id) { vehicleID = id; }
    void setFuelLevel(float fuel) { fuelLevel = fuel; }
    void setDistanceTravelled(double dist) { distanceTravelled = dist; }
    void setStatus(char st) { status = st; }
    void setIsAvailable(bool avail) { isAvailable = avail; }
    void setDriverName(string name) { driverName = name; }

    void updateStatus() {
        if (fuelLevel < 10.0 || !isAvailable)
            status = 'I';
        else
            status = 'A';
    }

    void displayInfo() {
        cout << "Vehicle ID: " << vehicleID << endl;
        cout << "Fuel Level: " << fuelLevel << endl;
        cout << "Distance Travelled: " << distanceTravelled << endl;
        cout << "Status: " << status << endl;
        cout << "Availability: " << (isAvailable ? "Yes" : "No") << endl;
        cout << "Driver Name: " << driverName << endl;
    }
};

// Global functions
void assignDriver(FleetVehicle &vehicle, string name) {
    vehicle.setDriverName(name);
    cout << "Driver assigned to Vehicle ID " << vehicle.getVehicleID()
         << ": " << vehicle.getDriverName() << endl;
}

void refuelVehicle(FleetVehicle &vehicle, float fuelAmount) {
    if (fuelAmount <= 0) {
        throw invalid_argument("Fuel amount must be positive!");
    }
    vehicle.setFuelLevel(vehicle.getFuelLevel() + fuelAmount);
    cout << "Vehicle ID " << vehicle.getVehicleID()
         << " refueled. New fuel level: " << vehicle.getFuelLevel() << endl;
}

int main() {
    FleetVehicle vehicles[3] = {
        FleetVehicle(101, 45.5, 120.0, 'A', true, "Raj"),
        FleetVehicle(102, 8.0, 300.0, 'A', true, "Priya"),
        FleetVehicle()
    };

    int choice, id;
    string name;
    float fuel;

    do {
        cout << "\n--- Fleet Vehicle Menu ---\n";
        cout << "1. Add Vehicle Details\n";
        cout << "2. Assign Driver\n";
        cout << "3. Refuel Vehicle\n";
        cout << "4. Update Status\n";
        cout << "5. Display Vehicle Info\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int vid; float fl; double dist; char st; bool avail; string dname;
                cout << "Enter Vehicle ID: "; cin >> vid;
                cout << "Enter Fuel Level: "; cin >> fl;
                cout << "Enter Distance Travelled: "; cin >> dist;
                cout << "Enter Status (A/I): "; cin >> st;
                cout << "Is Available (1/0): "; cin >> avail;
                cout << "Enter Driver Name: "; cin >> dname;
                vehicles[0] = FleetVehicle(vid, fl, dist, st, avail, dname);
                break;
            }
            case 2:
                cout << "Enter Vehicle Index (0-2): ";
                cin >> id;
                cout << "Enter Driver Name: ";
                cin >> name;
                assignDriver(vehicles[id], name);
                break;
            case 3:
                cout << "Enter Vehicle Index (0-2): ";
                cin >> id;
                cout << "Enter Fuel Amount: ";
                cin >> fuel;
                try {
                    refuelVehicle(vehicles[id], fuel);
                } catch (exception &e) {
                    cout << "Error: " << e.what() << endl;
                }
                break;
            case 4:
                cout << "Enter Vehicle Index (0-2): ";
                cin >> id;
                vehicles[id].updateStatus();
                cout << "Status updated.\n";
                break;
            case 5:
                cout << "Enter Vehicle Index (0-2): ";
                cin >> id;
                vehicles[id].displayInfo();
                break;
            case 6:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }
    } while (choice != 6);

    return 0;
}
