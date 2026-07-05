#include<iostream>
#include <string>


int main()
{
    double miles{};
    std::cout<< "Enter the number of miles:\n";
    std::cin >> miles;
    double kilometers = miles * 1.609;
    std::cout << miles << " miles is equivalant to " << kilometers << " kilometers.\n";

}