#include<iostream>
#include <string>
#include <array>
#include <algorithm>
#include <vector>


/*[3] If we define the median of a sequence as ‘‘a number so that exactly as many elements come
before it in the sequence as come after it,’’ fix the program in §3.6.3 so that it always prints
out a median. Hint: A median need not be an element of the sequence.*/

/*How to find the median
Sort the numbers in ascending order.
If there is an odd number of values, the median is the middle value.
If there is an even number of values, the median is the average of the two middle values*/

int main()
{
    std::cout << "Enter Set of temperature values: \n";
    std::vector<double> temps; // temperatures
    for (double temp; std::cin>>temp; ) // read into temp
        temps.push_back(temp); // put temp into vector
    
    // compute mean temperature:
    double sum = 0;
    for (double x : temps)
        sum += x;

    std::size_t siz{temps.size()};

    if(siz){
        std::cout << "Average temperature: " << sum / siz << '\n';

        // compute median temperature:
        std::sort(temps.begin(), temps.end()); //sort the temperatures

        std::cout << "Sorted Array: \n";
        for(auto itr : temps){
            std::cout << itr << ' ';
        }
        std::cout << '\n';
        
        std::cout << "Number of temps entered: " << siz << " \n";
        /*Odd number of elements*/
        if((siz % 2) != 0){
            std::cout << "Median temperature: " << temps[temps.size()/2] << '\n';        
        }
        else{
            std::cout << "Medians: " << temps[temps.size()/2] << ' ' << temps[temps.size()/2 - 1] << '\n';
            std::cout << "Median temperature: " << static_cast<double>((temps[temps.size()/2] + temps[temps.size()/2 - 1]) / 2.0f) << '\n';
        }
    }

    return 0;
}