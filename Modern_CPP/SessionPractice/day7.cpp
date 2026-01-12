#include <iostream>
#include <thread>
#include <future>  
#include <chrono>
#include <vector>
#include <mutex>
#include <functional>
#include <atomic>


void myFunc1(std::promise<int>& prom, int temp){
    prom.set_value(temp+10);
}

int main(){
    std::promise<int> prom;
    std::future<int> result = prom.get_future();

    std::async(std::launch::async,std::ref(myFunc1),std::ref(prom), 5);
    std::cout << "result value " << result.get() << '\n';

    return 0;
}