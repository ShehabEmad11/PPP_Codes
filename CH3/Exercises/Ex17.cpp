#include<iostream>
#include <string>
#include <array>
#include <algorithm>
#include <vector>
#include <math.h>


/*[17] Write a program to solve quadratic equations. A quadratic equation is of the form
ax2 + bx + c = 0. If you don’t know the formula for solving such an expression, do some
research. Remember, researching how to solve a problem is often necessary before a programmer
can teach the computer how to solve it. Use doubles for the user inputs for a, b, and
c. Since there are two solutions to a quadratic equation, output both x1 and x2.*/

template <typename T>
T GetUserInput(){
    T user_in{};

    if(std::cin>>user_in){
        return user_in;        
    }

    throw (std::runtime_error("Wrong user input "));
}

void Ex17(){
    std::cout << "Enter the quadratic equation coefficients a,b,c where Equation is: aX^2 +bX + c = 0 : ";
    
    double a{GetUserInput<double>()}, b{GetUserInput<double>()}, c{GetUserInput<double>()};

    double discremenat= b*b - 4*a*c;
    

    if(discremenat < 0){
        throw(std::runtime_error ("complex answer to quadratic equation not supported\n"));
    }
    else{
        const double sqrtDisc = std::sqrt(discremenat);
        const double twoA = 2*a;
        double X1{}, X2{};

        X1 = (-b + sqrtDisc) / twoA;
        X2 = (-b - sqrtDisc) / twoA;
        std::cout << "X1 = " << X1 << " , X2 = " << X2 << '\n'; 
    }

}

int main()
{
    try{
        while(1){
            Ex17();
            
        }
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return -1;
    }

    return 0;
}