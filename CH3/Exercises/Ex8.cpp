#include<iostream>
#include <string>
#include <array>
#include <algorithm>
#include <vector>


/*[8] Modify the ‘‘mini calculator’’ from exercise 6 to accept (just) single-digit numbers written as
either digits or spelled out.*/

template <typename T>
T GetUserInput(){
    T user_in{};

    if(std::cin>>user_in){
        return user_in;        
    }

    throw (std::runtime_error("Wrong user input "));
}

std::string GetSpelledIntEquivalent(int num){
    const std::vector<std::string> VEC_NUM_STRINGS{"zero","one","two","three","four","five","six","seven","eight","nine"};
    
    if((num >= 0) && (num < 10))
    {
        return VEC_NUM_STRINGS[num];
    }
    else{
        throw(std::runtime_error("Invalid input to GetSpelledIntEquivalent"));
    }
}

int GetIntFromSpelledEquivalent(std::string_view str){
    const std::vector<std::string> VEC_NUM_STRINGS{"zero","one","two","three","four","five","six","seven","eight","nine"};
    auto it = std::find(VEC_NUM_STRINGS.begin(), VEC_NUM_STRINGS.end(), str);
   
    if (it == VEC_NUM_STRINGS.end())
        throw(std::runtime_error("Invalid input to GetIntFromSpelledEquivalent"));
    
    return static_cast<int>(std::distance(VEC_NUM_STRINGS.begin(), it));
}

int GetNumber(){
    int num{};
    if(std::cin>>num){
        return num;
    }else{
        std::cin.clear();
        std::string str{};
        if(std::cin >> str){
            num = GetIntFromSpelledEquivalent(str);
            return num;
        }
        else{
            throw (std::runtime_error("Invalid input in GetNumber"));
        }
    }
}

void Calculator()
{
    std::cout << "enter three arguments: two int values and a character to represent an operation.: \n";
    int op1{GetNumber()},op2{GetNumber()};
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
        while(1){
            Calculator();
        }     
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return -1;
    }

    return 0;
}