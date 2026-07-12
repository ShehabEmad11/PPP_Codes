#include<iostream>
#include <string>
#include <array>
#include <algorithm>


/*[2]Write a program that reads a string from input and then, for each character read, prints out
the character and its integer value on a line.*/

int main()
{
    std::string input_str{};

    std::cout << "Enter the string: ";
    while(std::cin >> input_str){
        for(auto ch : input_str){
            std::cout << "\nCharacter = " <<ch << " Value = " <<static_cast<int>(ch) <<"\n"; 
            std::cout << "Enter the string: ";
        }
    }

    std::cout << "Invalid string entered, terminating ...\n";

    return 0;
}