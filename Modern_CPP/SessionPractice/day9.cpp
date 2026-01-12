// #include<iostream>

// //unary Left  Fold
// template<typename... Args>
// int sumLU(Args... arg){
//     return (... + arg);  //fold expression
// }

// // Unary Right fold -> left
// template<typename... Args>
// int sumRU(Args... arg){
//     return (arg + ...); // fold expression
// }

// template<typename... Args>  
// int sumLB(Args... arg){
//     return (100 + ... + arg); // fold expression
// }

// template<typename... Args>
// int sumRB(Args... arg){
//     return (arg + ... + 1000); // fold expression
// }

// int main(){
//     std::cout<<sumLU(1,2,3,4,5,6,7,8,9,10)<<"\n";
//     std::cout<<sumRU(1,2,3,4,5,6,7,8,9,10)<<"\n";

//     std::cout<<sumLB(1,2,3,4,5,6,7,8,9,10)<<"\n";
//     std::cout<<sumRB(1,2,3,4,5,6,7,8,9,10)<<"\n";

//     return 0;
// }




#include<iostream>
#include<string>


int main(){


    char arr[3] = {'H', 'N', 'M'};
    auto [a,b,c] = arr;
    std::cout<<a<<" "<<b<<" "<<c<<"\n";

    const auto& [a, b, c] = arr;
    //a = 10; 

    auto& [a, b, c] = arr; //by reference

    a = 10;  // modifies nums[0]

    std::cout << arr[0] << " " << arr[1] << " " << arr[2] << "\n";




    return 0;
}