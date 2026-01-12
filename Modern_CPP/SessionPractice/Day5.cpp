// #include<iostream>
// #include<thread>

// void greet()
// {
//     std::cout<<"Hello from thread!"<<std::endl;
// }

// int main()
// {
//     std::thread t1(greet);

//     // Wait for the thread to finish
//     t1.join();

//     std::cout<<"Thread has finished execution."<<std::endl;

//     return 0;
// }


#include <iostream>
#include <thread>
#include <chrono>

void greet(std::string name){   // thread function
    auto startTime = std::chrono::high_resolution_clock::now();
    
    std::cout << "Hello, Good Morning! " << name << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));

    auto endTime = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count();
    std::cout << "Done with thread" << name << "in time " << duration << std::endl;
}

int main(){
    std::thread th1(std::ref(greet),"One");
    std::thread th2(greet,"Two");
    std::thread th3(greet,"Three");

    std::vector<std::string> names = {"Alpha", "Beta", "Gamma"};
    std::vector<std::thread> threads;

    for(const auto& name : names){
        threads.emplace_back(greet, name);
    }

    for(auto& th : threads){
        if(th.joinable())
        th.join();
    }


    th1.join();
    th2.join();
    th3.join();
    std::cout << "done with main" << '\n';
    return 0;
}

// class MyDemoClass{
//     public:
//     void memberFunction(std::string name){
//         auto startTime = std::chrono::high_resolution_clock::now();
        
//         std::cout << "Hello, Good Morning! " << name << std::endl;
//         std::this_thread::sleep_for(std::chrono::seconds(1));

//         auto endTime = std::chrono::high_resolution_clock::now();
//         auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count();
//         std::cout << "Done with thread" << name << "in time " << duration << std::endl;
//     }
// };
// int main(){
//     MyDemoClass demo1, demo2, demo3;
//     std::thread demoTh1(&MyDemoClass::memberFunction,&demo1,"OneFunc");
//     std::thread demoTh2(&MyDemoClass::memberFunction,&demo2,"TwoFunc");
//     std::thread demoTh3(&MyDemoClass::memberFunction,&demo3,"ThreeFunc");

//     demoTh1.join();
//     demoTh2.join();
//     demoTh3.join();
// }




// class MyDemoClass{
//     private:
//         std::thread thread;
//         std::string name;

//         void memberFunction(std::string){
//             std::cout << "Hello, Good Morning! " << name << std::endl;
//         }

//     public:
//         MyDemoClass(std::string name): name(name) {}
//         ~MyDemoClass() {
//             if(thread.joinable()){ 
//                 thread.join();
//             }
//         }
//         void startThread(){
//             thread = std::thread(&MyDemoClass::memberFunction, this, name);
//         }
// };

// int main(){
//     MyDemoClass demo1("One"), demo2("Two"), demo3("Three");
//     demo1.startThread();
//     demo2.startThread();
//     demo3.startThread();

//     std:: cout << "done with main!\n";
//     return 0;
// }

