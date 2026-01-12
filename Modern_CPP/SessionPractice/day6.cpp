#include<iostream>
#include<thread>
#include<chrono>
#include<vector>
#include<mutex>

std::mutex myMutex;

// void print(int count, char ch){
//     for(int i=0; i<count; ++i){
//         std::cout << ch;
//         std::this_thread::sleep_for(std::chrono::milliseconds(250));
//     }
//     std::cout<<"\n";
//     mymutex.lock();
// }

 int counter = 0;

// void increment(){
//     mymutex.lock();
//     ++counter;
//     std::cout << "Counter: " << counter << std::endl;
//     mymutex.unlock();   
// }

// void increment(){
//     std::lock_guard<std::mutex> guard(mymutex);
//     ++counter;
//     std::cout << "Counter: " << counter << std::endl;
// }

// int main(){
//     std::thread t1(std::ref(print),5,'*');
//     std::thread t2(print,7,'#');
//     std::thread t3(print,10,'#');

//     t1.join();
//     t2.join();
//     t3.join();

// std::vector<std::thread> threads;

// threads.emplace_back(std::ref(increment));
// threads.emplace_back(std::ref(increment));
// threads.emplace_back(std::ref(increment));
// threads.emplace_back(std::ref(increment));
// threads.emplace_back(std::ref(increment));

// for(auto& th : threads){
//     if(th.joinable())
//         th.join();
// }

//     return 0;
// }










// void increment(){
//     //std::lock_guard<std::mutex> lock(myMutex);
//     myMutex.lock();
//     ++counter;
//     std::cout << "counter = " << counter << '\n';
//     throw std::runtime_error("Exception");
//     myMutex.unlock();
// }


// void increment(){
//     std::lock_guard<std::mutex> lock(myMutex);
//     ++counter;
//     std::cout << "counter = " << counter << '\n';
//     throw std::runtime_error("Exception");
// }

void increment(){
    std::unique_lock<std::mutex> myUniqueLock(myMutex);
    myUniqueLock.lock();
    ++counter;
    myUniqueLock.unlock();
    std::cout << "counter = " << counter << '\n';
    throw std::runtime_error("Exception");
}


int main(){
    std::vector<std::thread> threads;

    for(int i = 0; i< 10; i++){
        threads.emplace_back([]{
            try{
                increment();
            }
            catch(const std::exception& err){
                std::cerr << err.what() << std::endl;
            }
        });
    }

    for(auto& thread: threads){
        thread.join();
    }

    return 0;
}
