#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

/**
 * @class FleetVehicle
 * @brief Represents a delivery vehicle in the logistics fleet.
 */
class FleetVehicle {
private:
    int vehicleId;
    float fuelLevel;
    double distanceTravelled;
    char status;            // 'A' for Active, 'I' for Inactive
    bool available;
    string driverName;

public:
    /** Default constructor */
    FleetVehicle()
        : vehicleId(0), fuelLevel(50.0f), distanceTravelled(0.0),
          status('A'), available(true), driverName("Unassigned") {}

    /** Parameterized constructor */
    FleetVehicle(int id, float fuel, double distance, char st,
                 bool isAvailable, const string& name)
        : vehicleId(id), fuelLevel(fuel), distanceTravelled(distance),
          status(st), available(isAvailable), driverName(name) {}

    /** Destructor */
    ~FleetVehicle() {
        cout << "Destructor called for Vehicle ID: " << vehicleId << endl;
    }

    // ---------------- Getters ----------------
    int getVehicleId() const { return vehicleId; }
    float getFuelLevel() const { return fuelLevel; }
    double getDistanceTravelled() const { return distanceTravelled; }
    char getStatus() const { return status; }
    bool isAvailable() const { return available; }
    string getDriverName() const { return driverName; }

    // ---------------- Setters ----------------
    void setVehicleId(int id) { vehicleId = id; }
    void setFuelLevel(float fuel) { fuelLevel = fuel; }
    void setDistanceTravelled(double distance) { distanceTravelled = distance; }
    void setStatus(char st) { status = st; }
    void setAvailable(bool isAvailable) { available = isAvailable; }
    void setDriverName(const string& name) { driverName = name; }

    /**
     * @brief Updates vehicle status based on fuel and availability.
     */
    void updateStatus() {
        status = (fuelLevel < 10.0f || !available) ? 'I' : 'A';
    }

    /**
     * @brief Displays vehicle information in a formatted manner.
     */
    void displayInfo() const {
        cout << "\n----- Vehicle Details -----\n";
        cout << "Vehicle ID          : " << vehicleId << endl;
        cout << "Fuel Level          : " << fuelLevel << endl;
        cout << "Distance Travelled  : " << distanceTravelled << endl;
        cout << "Status              : " << status << endl;
        cout << "Available           : " << (available ? "Yes" : "No") << endl;
        cout << "Driver Name         : " << driverName << endl;
        cout << "---------------------------\n";
    }
};

// ---------------- Global Functions ----------------

/**
 * @brief Assigns a driver to a vehicle.
 */
void assignDriver(FleetVehicle& vehicle, const string& name) {
    vehicle.setDriverName(name);
    cout << "✅ Driver '" << vehicle.getDriverName()
         << "' assigned to Vehicle ID " << vehicle.getVehicleId() << ".\n";
}

/**
 * @brief Refuels a vehicle by the given amount.
 * @throws invalid_argument if fuelAmount <= 0
 */
void refuelVehicle(FleetVehicle& vehicle, float fuelAmount) {
    if (fuelAmount <= 0.0f) {
        throw invalid_argument("Fuel amount must be greater than 0.");
    }
    float newLevel = vehicle.getFuelLevel() + fuelAmount;
    vehicle.setFuelLevel(newLevel);
    cout << "⛽ Vehicle ID " << vehicle.getVehicleId()
         << " refueled. New fuel level: " << vehicle.getFuelLevel() << endl;
}

/**
 * @brief Displays menu and performs user operations.
 */
int main() {
    FleetVehicle vehicles[3] = {
        FleetVehicle(101, 45.5f, 120.0, 'A', true, "Raj"),
        FleetVehicle(102, 8.0f, 300.0, 'A', true, "Priya"),
        FleetVehicle() // default constructor
    };

    int choice;
    do {
        cout << "\n========= Fleet Vehicle Menu =========\n";
        cout << "1. Add Vehicle Details\n";
        cout << "2. Assign Driver\n";
        cout << "3. Refuel Vehicle\n";
        cout << "4. Update Status\n";
        cout << "5. Display Vehicle Info\n";
        cout << "6. Exit\n";
        cout << "Enter choice (1-6): ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int id; float fuel; double dist; char st; bool avail; string dname;
                cout << "Enter Vehicle ID: "; cin >> id;
                cout << "Enter Fuel Level: "; cin >> fuel;
                cout << "Enter Distance Travelled: "; cin >> dist;
                cout << "Enter Status (A/I): "; cin >> st;
                cout << "Is Available (1/0): "; cin >> avail;
                cout << "Enter Driver Name: "; cin >> dname;

                vehicles[0] = FleetVehicle(id, fuel, dist, st, avail, dname);
                cout << "✅ Vehicle details added.\n";
                break;
            }

            case 2: {
                int index;
                cout << "Enter Vehicle Index (0-2): "; cin >> index;
                if (index < 0 || index > 2) { cout << "❌ Invalid index.\n"; break; }
                string name;
                cout << "Enter Driver Name: "; cin >> name;
                assignDriver(vehicles[index], name);
                break;
            }

            case 3: {
                int index;
                cout << "Enter Vehicle Index (0-2): "; cin >> index;
                if (index < 0 || index > 2) { cout << "❌ Invalid index.\n"; break; }
                float amount;
                cout << "Enter Fuel Amount: "; cin >> amount;
                try {
                    refuelVehicle(vehicles[index], amount);
                } catch (const exception& ex) {
                    cout << "⚠️ Error: " << ex.what() << endl;
                }
                break;
            }

            case 4: {
                int index;
                cout << "Enter Vehicle Index (0-2): "; cin >> index;
                if (index < 0 || index > 2) { cout << "❌ Invalid index.\n"; break; }
                vehicles[index].updateStatus();
                cout << "🔄 Status updated for Vehicle ID "
                     << vehicles[index].getVehicleId() << ".\n";
                break;
            }

            case 5: {
                int index;
                cout << "Enter Vehicle Index (0-2): "; cin >> index;
                if (index < 0 || index > 2) { cout << "❌ Invalid index.\n"; break; }
                vehicles[index].displayInfo();
                break;
            }

            case 6:
                cout << "🚪 Exiting program...\n";
                break;

            default:
                cout << "❌ Invalid choice.\n";
        }
    } while (choice != 6);

    return 0;
}
