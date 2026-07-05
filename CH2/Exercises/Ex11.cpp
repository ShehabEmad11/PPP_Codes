#include<iostream>
#include <string>
#include <array>
#include <algorithm>


void PrintCoinValue(std::string coin_type, int num){
    if(num == 0){
        std::cout << "You don\'t have any " << coin_type << '\n';
        return;
    }
    else if(num == 1){
        if(coin_type == "pennies"){
            coin_type = "penny";
        }else{
            coin_type.pop_back();
        }
    }
    
    std::cout << "You have " << num<< " " << coin_type << '\n';
}

int GetNumOfCoins(std::string coin_type){
    int num{};
    std::cout << "Enter the how many " << coin_type << " you have ?";
    if(std::cin >> num){
        return num;            
    }
    else{
        throw std::runtime_error("invalid input\n");
    }
}

int main()
{
    /*Exercise 11*/
    try{
        int pennies{GetNumOfCoins("pennies")};
        int nickels{GetNumOfCoins("nickels")};
        int dimes{GetNumOfCoins("dimes")};
        int quarters{GetNumOfCoins("quarters")};
        int half_dollars{GetNumOfCoins("half_dollars")};
        int dollars{GetNumOfCoins("dollars")};

        PrintCoinValue("pennies", pennies);
        PrintCoinValue("nickels", nickels);
        PrintCoinValue("dimes", dimes);
        PrintCoinValue("quarters", quarters);
        PrintCoinValue("half_dollars", half_dollars);
        PrintCoinValue("dollars", dollars);
        
        double total_amount = dollars * 100 + half_dollars * 50 + quarters * 25 + dimes * 10 + nickels * 5 + pennies;
        std::cout << "The total amount of money you have is $" << total_amount / 100 << '\n';
    }
    catch(std::runtime_error& e){
        std::cout << e.what() << '\n';
        return -1;
    }
   
}