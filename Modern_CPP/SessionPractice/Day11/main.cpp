#include "Sensor.h"
#include <vector>
#include <algorithm>

int main(){
    std::vector<Sensor> sensors = {
        {"Speed Sensor", 1, 45.6},
        {"Temperature Sensor", 3, 78.2},
        {"Pressure", 2, 101.3},
        {"Altitude", 5, 1000}
    };

    std::for_each(sensors.begin(), sensors.end(), [](const Sensor& sensor){ sensor.display(); }); 
    

    
}