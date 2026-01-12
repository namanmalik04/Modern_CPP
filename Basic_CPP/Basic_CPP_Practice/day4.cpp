class VehicleSpeedControl{
    private:
        int speed = 0;
    public:
      
        void setSpeed(int spd){
            if(spd < 0){
                throw std::invalid_argument("[Invalid speed value: " + std::to_string(spd) + "]");
            }
            else if(spd > 150){
                throw std::out_of_range("[Speed out of range: " + std::to_string(spd) + "]");
            }   
            speed = spd;
        }
        ~VehicleSpeedControl(){
            std::cout << "VehicleSpeedControl object destroyed" << '\n';
        }    
};

int main(){
    VehicleSpeedControl car;
    try{
        car.setSpeed(20);
    }catch(const std::invalid_argument& msg){
        std::cout << msg.what() << '\n';
    }

    try{
        car.setSpeed(-20);
    }catch(const std::invalid_argument& msg){
        std::cout << msg.what() << '\n';
    }

    try{
        car.setSpeed(500);
    }catch(const std::out_of_range& msg){
        std::cout << msg.what() << '\n';
    }   
}





// class NegativeSpeedValueException: public std::exception{
//     public:
//         const char* what() const noexcept override{
//             return "Negative speed value is not allowed";
//         }
// };
// class SpeedLimitException: public std::exception{
//     public:
//         const char* what() const noexcept override{
//             return "Speed limit exceeded";
//         }
// };

// class VehicleSpeedControl{
//     private:
//         int speed = 0;
//     public:
      
//         void setSpeed(int spd) {
//             if(spd < 0){
//                 throw NegativeSpeedValueException();
//             }
//             else if(spd > 150){
//                 throw SpeedLimitException();
//             }   
//             speed = spd;
//         }
//         ~VehicleSpeedControl(){
//             std::cout << "VehicleSpeedControl object destroyed" << '\n';
//         }    
// };

// int main(){
//     VehicleSpeedControl car;
//     try{
//         car.setSpeed(20);
//     }catch(const NegativeSpeedValueException& msg){
//         std::cout << msg.what() << '\n';
//     }

//     try{
//         car.setSpeed(-20);
//     }catch(const NegativeSpeedValueException& msg){
//         std::cout << msg.what() << '\n';
//     }

//     try{
//         car.setSpeed(500);
//     }catch(const SpeedLimitException& msg){
//         std::cout << msg.what() << '\n';
//     }   
// }