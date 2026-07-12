#include<iostream>
#include <string>
#include <array>
#include <algorithm>
#include <vector>


/*[6]Write a program that performs as a very simple calculator. Your calculator should be able to
handle the four basic math operations – add, subtract, multiply, and divide – on two input values.
Your program should prompt the user to enter three arguments: two double values and a
character to represent an operation. If the entry arguments are 35.6, 24.1, and '+', the program
output should be The sum of 35.6 and 24.1 is 59.7.*/

template <typename T>
T GetUserInput(){
    T user_in{};

    if(std::cin>>user_in){
        return user_in;        
    }

    throw (std::runtime_error("Wrong user input "));
}

void Calculator()
{
    std::cout << "enter three arguments: two double values and a character to represent an operation.: \n";
    double op1{GetUserInput<double>()},op2{GetUserInput<double>()};
    char operation{GetUserInput<char>()};
    double result{};
    switch (operation)
    {
        case '+':
            result = op1 + op2;
            std::cout << "The sum of ";
        break;

        case '-':
            result = op1 - op2;
            std::cout << "The difference of ";
        break;

        case '*':
            result = op1 * op2;
            std::cout << "The multiplication of ";
        break;
        
        case '/':
            if(op2 != 0){
                result = op1 / op2;
                std::cout << "The Division of ";
            }
            else{
                throw(std::runtime_error("Invalid Division by 0\n"));
            }
        break;

        default:
            throw(std::runtime_error("Invalid Operation\n"));
        break;
    }

    std::cout << op1 << " and "<< op2 << " is "<<result<<'\n';
    
}

int main()
{
    try{
        Calculator();
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return -1;
    }

    return 0;
}