#include<iostream>
#include <string>
#include <array>
#include <algorithm>



int main()
{
    /*Exercise 8*/
    std::cout << "Enter the number \n";
    int n{};
    std::cin >> n;
    if( n % 2 == 0){
        std::cout << "The number " << n << " is even\n";
    }
    else{
        std::cout << "The number " << n << " is odd\n";
    }
}