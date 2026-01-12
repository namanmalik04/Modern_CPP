#include <iostream>


// Composition
// - individual parts can not exists independtly
// - want to control ownership and lifetime
// - has a relationship
class Engine{
    public:
        void ignite(){
            std::cout << "Engine ignited!" << std::endl;
        }
};

class Breaksystem{
    public:
        void apply(){
            std::cout << "Breaks applied!" << std::endl;
        }
};

class Car{
    private:
        Engine engine;
        Breaksystem breaks;
    public:
        void start(){
            engine.ignite();
            std::cout << "Car Started \n";
        }
        void stop(){
            breaks.apply();
            std::cout << "Car Stopped \n";
        }    
};

int main() {
    Car car;    // no separate object is created for engine and breaks
    car.start();
    car.stop();

    return 0;
}


// Aggregation
// DiagnosticTool class is not owming Sensor
// loose relationship
// using one in another but without ownership

// class Sensor{
//     public:
//         std::string sensorID;
//         Sensor(std::string id): sensorID(id){}
//         double readSensor(){
//             return 12.5;
//         }
// };

// class DiagnosticTool{
//     private:
//         Sensor* sensor;
//     public:
//         DiagnosticTool(Sensor* s): sensor(s){}
//         void runDiagnostics(){
//             std::cout << "Sensor ID: " << sensor->sensorID << " Reading: " << sensor->readSensor() << std::endl;
//         }
// };

// int main(){

//     Sensor* sensor = new Sensor("BreakSensor");
//     DiagnosticTool tool(sensor);
//     tool.runDiagnostics();
//     return 0;
// }