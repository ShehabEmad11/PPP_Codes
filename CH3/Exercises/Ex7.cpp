#include<iostream>
#include <string>
#include <array>
#include <algorithm>
#include <vector>


/*[7] Make a vector holding the ten string values "zero", "one", . . . "nine". Use that in a program
that converts a digit to its corresponding spelled-out value; e.g., the input 7 gives the output
seven. Have the same program, using the same input loop, convert spelled-out numbers into
their digit form; e.g., the input seven gives the output 7.*/

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

void Calculator()
{
    
    
}

int main()
{
    try{
        while(1){
            std::cout << "Enter the digit spell: ";        
            int val{GetIntFromSpelledEquivalent(GetUserInput<std::string>())};
            std::cout << "The equivalent value = "<< val <<"\n\n";

            std::cout << "Enter the number : ";        
            std::string spell{GetSpelledIntEquivalent(GetUserInput<int>())};
            std::cout << "The equivalent name = "<< spell <<"\n\n";
        }
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return -1;
    }

    return 0;
}