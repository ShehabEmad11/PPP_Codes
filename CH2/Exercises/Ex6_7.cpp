#include<iostream>
#include <string>
#include <array>
#include <algorithm>

template<typename T>
void Arrange(){
    std::array<T,3> Data{};
    std::cout << "Enter 3 values: \n ";
    std::cin >> Data[0] >> Data[1] >> Data[2];

    std::sort (Data.begin(), Data.end());

    std::cout << Data[0] << ',' << Data[1] << ',' << Data[2] << '\n';
}

int main()
{
    /*Exercise 6*/
    //Arrange<int>();
    
    /*Exercise 7*/
    Arrange<std::string>();
}