// #include<iostream>
// #include<variant>

// struct visitor
// {
//     void operator()(int var){std::cout<< " Accessing Integer VAle " << var <<"\n";}
//     void operator()(char var){std::cout<< " Accessing Character Value " << var <<"\n"; }     
//     void operator()(double var){std::cout<< " Accessing Double Value " << var <<"\n";}
// };

// std::variant<int,std::string> myfunction(int arg){
//     if(arg>0)
//     return 10;

//     else{
//         return std::string("OK");
//     }
// }

// int main()
// {
//     std::variant<int,char,double>myVariant;

//     myVariant = 10;
//     std::cout<< std::get<int>(myVariant)<<"\n";

//     myVariant = 'A';
//     std::cout<< std::get<char>(myVariant)<<"\n";

//     myVariant = 3.14;
//     std::cout<< std::get<double>(myVariant)<<"\n";


//     try{
//     std::cout<< std::get<int>(myVariant)<<"\n";

//     }catch(const std::bad_variant_access& e){
//     std::cout<<"Error invalid type "<<"\n";
//     }



//     //----------------
//     std::visit(visitor(),myVariant);



//     //--------
//     myVariant = 'K';
//     std::visit([](auto&& var) {std::cout<<" Accessing Value "<< var <<"\n";}, myVariant);

//     auto var = myfunction(10);
//     std::visit([](auto&& arg) {std::cout<<" Accessing Value "<< arg <<"\n";}, var);


//     return 0;
// }



#include<iostream>
#include<variant>   

class Car{

    public:
    void display(){
        std::cout<<"Car is Running"<<"\n";
    }
};

class Truck{
    public:
    void display(){
        std::cout<<"Truck is Running"<<"\n";
    }
};

class Bike{
    public:
    void display(){
        std::cout<<"Bike is Running"<<"\n";
    }
};

void operation(std::variant<Car,Truck,Bike> vehicle){
    std::visit([](auto&& arg){ arg.display();}, vehicle);
}
int main()
{
    Car car;
    Truck truck;
    Bike bike;


    operation(car);
    operation(truck);
    operation(bike);

    return 0;
}