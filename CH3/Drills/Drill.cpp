#include<iostream>
#include <string>
#include <numeric>
#include <vector>
#include <algorithm>

template <typename T>
void Drill(){
/*
    [1] Write a program that consists of a while-loop that (each time around the loop) reads in
    two ints and then prints them. Exit the program when a terminating '|' is entered.
    [2] Change the program to write out the smaller value is: followed by the smaller of the numbers
    and the larger value is: followed by the larger value.
    [3] Augment the program so that it writes the line the numbers are equal (only) if they are
    equal.
    [4] Change the program so that it uses doubles instead of ints.
*/

    T num1{},num2{};
    while(1){
        std::cout << "Enter the two numbers\n";
        if(std::cin >> num1 >> num2){
            std::cout << "Num1 Entererd is " << num1 << " while Num2 enetered is " << num2 << '\n';
            if(num1 == num2){
                std::cout << "The numbers are equal.\n";
            }
            else{
                std::cout << "The Larger number is " << ((num1 >= num2)? num1 : num2) << " The smaller number is " << ((num1<num2)? num1 : num2) << '\n';
            }

        }else{
            std::cin.clear();
            std::cin.ignore();
            break;
        }
    }
}


void Drill_5(){
    /*
    [5] Change the program so that it writes out the numbers are almost equal after writing out
    which is the larger and the smaller if the two numbers differ by less than 1.0/100.
    */

    double num1{},num2{};
    while(1){
        std::cout << "Enter the two numbers\n";
        if(std::cin >> num1 >> num2){
            std::cout << "Num1 Entererd is " << num1 << " while Num2 enetered is " << num2 << '\n';
            if(std::abs(num1 - num2) < 1.0/100){
                std::cout << "The numbers are almost equal.\n";
            }
            else{
                std::cout << "The Larger number is " << ((num1 >= num2)? num1 : num2) << " The smaller number is " << ((num1<num2)? num1 : num2) << '\n';
            }

        }else{
            std::cin.clear();
            std::cin.ignore();
            break;
        }
    }
}


void Drill_6(){
    /*
    [6] Now change the body of the loop so that it reads just one double each time around.
    Define two variables to keep track of which is the smallest and which is the largest value
    you have seen so far. Each time through the loop write out the value entered. If it’s the
    smallest so far, write the smallest so far after the number. If it is the largest so far, write
    the largest so far after the number.
    */

    double num,smallest{},largest{};
    while(1){
        std::cout << "Enter a number\n";
        if(std::cin >> num){
            std::cout << "Num Entererd is " << num;
            if (num < smallest){
                smallest = num;
                std::cout << " The smallest so far";
            }
            else if(num > largest){
                largest = num;
                std::cout << " The largest so far";
            }
            std::cout <<'\n';

        }else{
            std::cin.clear();
            std::cin.ignore();
            break;
        }
    }
}


void Drill_7_8_9(){
/*
    [7]Add a unit to each double entered; that is, enter values such as 10cm, 2.5in, 5ft, or 3.33m.
    Accept the four units: cm, m, in, ft. Assume conversion factors 1m==100cm, 1in==2.54cm,
    1ft==12in. Read the unit indicator into a string. You may consider 12 m (with a space
    between the number and the unit) equivalent to 12m (without a space).
    [8] Reject values without units or with ‘‘illegal’’ representations of units, such as y, yard,
    meter, km, and gallons.
    [9]Keep track of the sum of values entered (as well as the smallest and the largest) and the
    number of values entered. When the loop ends, print the smallest, the largest, the number
    of values, and the sum of values. Note that to keep the sum, you have to decide on a unit
    to use for that sum; use meters.*/

    double num{}, smallest{std::numeric_limits<double>::max()}, largest{std::numeric_limits<double>::lowest()}, sum{};
    int num_values{};
    std::string unit{};
    #define FACTOR_cm_to_m  (0.01)
    #define FACTOR_in_to_m  (0.0254)
    #define FACTOR_ft_to_m  (0.3048)   
    while(1){
        std::cout << "Enter a number\n";
        if(std::cin >> num >> unit){
            std::cout << "Num Entererd is " << num << " unit is -" << unit <<"-\n";
            if(unit == "in"){
                num *= FACTOR_in_to_m;
            }
            else if (unit == "cm"){
                num *= FACTOR_cm_to_m;
            }
            else if (unit == "ft"){
                num *= FACTOR_ft_to_m;
            }
            else if (unit == "m"){
                num = num;
            }
            else if (unit =="|")
            {
                break;
            }
            else
            {
                std::cout << "unit rejected\n";
                continue;
            }

            num_values++;

            if (num < smallest){
                smallest = num;
            }
            
            if(num > largest){
                largest = num;
            }
            

            sum += num;
            std::cout <<'\n';

        }else{
            std::cin.clear();
            std::cin.ignore();
            break;
        }
    }
    if(num_values){
        std::cout << "Smallest = " <<smallest << "m Largest = " << largest << "m Num of values entered = " << num_values <<  " Sum is equal to " << sum << "m \n";
    }

}


void Drill_10_11(){
/*
    [10] Keep all the values entered (converted into meters) in a vector. At the end, write out
    those values.
    [11] Before writing out the values from the vector, sort them (that’ll make them come out in
    increasing order).
*/

    std::vector<double> num_vec{};
    double num{}, smallest{std::numeric_limits<double>::max()}, largest{std::numeric_limits<double>::lowest()}, sum{};
    int num_values{};
    std::string unit{};
    #define FACTOR_cm_to_m  (0.01)
    #define FACTOR_in_to_m  (0.0254)
    #define FACTOR_ft_to_m  (0.3048)   
    while(1){
        std::cout << "Enter a number\n";
        if(std::cin >> num >> unit){
            std::cout << "Num Entererd is " << num << " unit is -" << unit <<"-\n";
            if(unit == "in"){
                num *= FACTOR_in_to_m;
            }
            else if (unit == "cm"){
                num *= FACTOR_cm_to_m;
            }
            else if (unit == "ft"){
                num *= FACTOR_ft_to_m;
            }
            else if (unit == "m"){
                num = num;
            }
            else if (unit =="|")
            {
                break;
            }
            else
            {
                std::cout << "unit rejected\n";
                continue;
            }

            num_vec.push_back(num);
            std::sort(num_vec.begin(),num_vec.end());
            num_values++;

            if (num < smallest){
                smallest = num;
            }
            
            if(num > largest){
                largest = num;
            }
            

            sum += num;
            std::cout <<'\n';

        }else{
            std::cin.clear();
            std::cin.ignore();
            break;
        }
    }

    if(num_values){
        std::cout << "Sorted Numbers: \n";
        std::cout << "Smallest = " <<smallest << "m Largest = " << largest << "m Num of values entered = " << num_values <<  " Sum is equal to " << sum << "m \n";
        std::cout << "Sorted Numbers: \n";
        for(auto iter : num_vec){
            std::cout << iter << "m\n";
        }
    }
}

int main()
{
    /*Drills 1, 2, 3*/
    //Drill<int>();
    
    /*Drill 4*/
    //Drill<double>();

    /*Drill 5*/
    //Drill_5();

    /*Drill 6*/
    //Drill_6();

    /*Drills 7, 8, 9*/
    //Drill_7_8_9();

    /*Drill 10 & 11*/
    Drill_10_11();

}