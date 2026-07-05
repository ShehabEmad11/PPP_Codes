#include<iostream>
#include <string>
#include <array>
#include <algorithm>



int main()
{
    /*Exercise 9*/
    std::cout << "Enter the spelled number in small letters\n";
    std::string spelled_digit{};
    std::cin >> spelled_digit;
    if( spelled_digit == "zero"){
        std::cout << "The number is 0 \n";
    }
    else if( spelled_digit == "one"){
        std::cout << "The number is 1 \n";
    }
    else if( spelled_digit == "two"){
        std::cout << "The number is 2 \n";
    }
    else if( spelled_digit == "three"){
        std::cout << "The number is 3 \n";
    }
    else if( spelled_digit == "four"){
        std::cout << "The number is 4 \n";
    }
    else if( spelled_digit == "five"){
        std::cout << "The number is 5 \n";
    }
    else if( spelled_digit == "six"){
        std::cout << "The number is 6 \n";
    }
    else if( spelled_digit == "seven"){
        std::cout << "The number is 7 \n";
    }
    else if( spelled_digit == "eight"){
        std::cout << "The number is 8 \n";
    }
    else if( spelled_digit == "nine"){
        std::cout << "The number is 9 \n";
    }else{
        std::cout << spelled_digit << " is not a number i know\n";
    }
}