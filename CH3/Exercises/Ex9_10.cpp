#include<iostream>
#include <string>
#include <array>
#include <algorithm>
#include <vector>


/*[9] There is an old story that the emperor wanted to thank the inventor of the game of chess and
asked the inventor to name his reward. The inventor asked for one grain of rice for the first
square, 2 for the second, 4 for the third, and so on, doubling for each of the 64 squares. That
may sound modest, but there wasn’t that much rice in the empire! Write a program to calculate
how many squares are required to give the inventor at least 1000 grains of rice, at least
1,000,000 grains, and at least 1,000,000,000 grains. You’ll need a loop, of course, and probably
an int to keep track of which square you are at, an int to keep the number of grains on
the current square, and an int to keep track of the grains on all previous squares. We suggest
that you write out the value of all your variables for each iteration of the loop so that you can
see what’s going on.

[10] Try to calculate the number of rice grains that the inventor asked for in exercise 9 above.
You’ll find that the number is so large that it won’t fit in an int or a double. Observe what
happens when the number gets too large to represent exactly as an int and as a double. What
is the largest number of squares for which you can calculate the exact number of grains
(using an int)? What is the largest number of squares for which you can calculate the approximate
number of grains (using a double)?*/

template <typename T>
T GetUserInput(){
    T user_in{};

    if(std::cin>>user_in){
        return user_in;        
    }

    throw (std::runtime_error("Wrong user input "));
}


template <typename s_t>
unsigned int GetSquaresForRice(s_t riceQty){
    unsigned int numSquares{1};

    if(riceQty == 0){
        numSquares = 0;
    }
    else{
        numSquares = 1;
        std::cout << "@Square " << 1 << " you have total of " << 1 << ", Rice Grains\n";
        s_t grainsOnSquare{1}, totalGrains{1};
        while( totalGrains < riceQty )
        {
            grainsOnSquare *= 2;
            totalGrains += grainsOnSquare;
            numSquares++;
            std::cout << "@Square " << numSquares << " You Get Additional " << grainsOnSquare << " Rices grains, now you have total of " << totalGrains << ", Rice Grains\n";
        }
    }

    return numSquares;
}

template <typename s_t>
s_t GetRiceForSquares(unsigned int numSquares){
    s_t numGrains{};
    
    if(numSquares <=64){
        if(numSquares == 0){
            numGrains = 0;
        }
        else{
            numGrains = 1;
            s_t nSqVal{1};
            std::cout << "@Square " << 1 << " you have "<< nSqVal << " grains, which gives total of " << numGrains << ", Rice Grains\n";
            for(unsigned int n{2}; n <= numSquares; n++){
                nSqVal*= 2;
                numGrains += nSqVal;
                std::cout << "@Square " << n << " you have another "<< nSqVal << " grains, which gives total of " << numGrains << ", Rice Grains\n";

            }
        }
    }
    else{
        throw(std::runtime_error("Invalid number of squares"));
    }

    return numGrains;
}


void Ex9(){
    unsigned int squaresNeeded{};
    std::cout << "Tell me the quanitiy of rice you want :";
    unsigned int neededAmtRice{GetUserInput<unsigned int>()};
    squaresNeeded = GetSquaresForRice(neededAmtRice);

    std::cout << "We would need "<< squaresNeeded << " square to provide "<< neededAmtRice << " Rice Grain(s)\n";

    if(squaresNeeded > 64){
        std::cout << "Amount can't be provided (more than maximum chess board equivalent amount of rice \n)";
    }
}

template <typename s_t>
void Ex10(){
    std::cout <<"Now tell me how many squares you would like to get rewarded for: ";
    unsigned int numSquares{GetUserInput<unsigned int>()};
    s_t riceAmt{GetRiceForSquares<s_t>(numSquares)};
    std::cout << "The equivalent number of rices is " << riceAmt;
}

int main()
{
    try{
        while(1){
            //Ex9();
            
            Ex10<unsigned long long int>();

            //Ex10<double>();
        }
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return -1;
    }

    return 0;
}