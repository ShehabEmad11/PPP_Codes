#include<iostream>
#include <string>

template<typename T>
void compare(){
    T var1{}, var2{};
    std::cout << "Enter two numbers:\n";
    std:: cin >>var1 >> var2;

    std::cout << "Smaller value is " << ((var1 < var2)? var1 : var2) << '\n';
    std::cout << "Larger value is " << ((var1 >= var2)? var1 : var2) << '\n';
    std:: cout << "Sum is " << var1 + var2 << '\n';
    std:: cout << "Diff is " << var1 - var2 << '\n';
    std:: cout << "Product is " << var1 * var2 << '\n';
    std:: cout << "Ratio is " << var1 / var2 << '\n';

}

int main()
{
    //Exercise 4
    compare<int>();
    
    //Exercise 5
    //compare<double>();
}