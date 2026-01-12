#include<iostream>
#include<algorithm>
#include<vector>

void display(std::vector<int>& temp){
        for(auto it = temp.begin(); it != temp.end(); ++it){
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

int main(){

    std::vector<int> src = {1, 2, 3, 4, 5};
    std::vector<int> dest,dest2, desif;

    //copy all elements from src to dest
    dest.resize(src.size());
    std::copy(src.begin(), src.end(), dest.begin());
    display(dest);

     //copy first 4 elements from src to dest2  
    dest2.resize(4);    
    std::copy_n(src.begin(), 4, dest2.begin());
    display(dest2);

    //copy only even numbers from src to desif
    desif.resize(src.size());
    std::copy_if(src.begin(), src.end(), desif.begin(), [](int val){return val % 2 == 0;});
    display(desif);

    auto location = find(src.begin(), src.end(), 3);

    if(location != src.end())
    std::cout<< *location <<std::endl;

    auto loc2 = find_if(src.begin(), src.end(), [](int val){ return val%2 !=0 ;});

    if(loc2 != src.end())
    std::cout<< *loc2 <<std::endl;
    


    return 0;
}