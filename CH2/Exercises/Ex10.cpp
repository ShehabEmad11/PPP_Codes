#include<iostream>
#include <string>
#include <array>
#include <algorithm>



int main()
{
    /*Exercise 10*/
    std::cout << "Enter the numeric process in the format of operation operand1 operand2\n";
    std::string operation{};
    double op1{}, op2{};
    double result{};
    if(std::cin >> operation >> op1 >> op2){
        if( operation == "+"){
            result = op1 + op2;
        }else if (operation == "-"){
            result = op1 - op2;
        }else if (operation == "*"){
            result = op1 * op2;
        }else if (operation == "/"){
            if(op2 != 0){
                result = op1 / op2;
            }else{
                std::cout << "division by zero is not valid\n";
                return -1; 
            }
        }else{
            std::cout << "invalid operation\n";
            return -1;
        }
        std::cout << "The result of " << op1 << ' ' << operation << ' ' << op2 << " is " << result << '\n';
    }else{
        std::cout << "invalid input\n";
        return -1;
    }
}