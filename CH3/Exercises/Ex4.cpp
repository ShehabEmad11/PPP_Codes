#include<iostream>
#include <string>
#include <array>
#include <algorithm>
#include <vector>


/*[4]Read a sequence of double values into a vector. Think of each value as the distance between
two cities along a given route. Compute and print the total distance (the sum of all distances).
Find and print the smallest and greatest distance between two neighboring cities.
Find and print the mean distance between two neighboring cities.*/



int main()
{
    std::cout << "Enter Distances between two cities: \n";
    std::vector<double> distances; // temperatures
    for (double dist; std::cin>>dist; ) // read into temp
        distances.push_back(dist); // put distance into vector
    
    // compute mean temperature:
    double sum = 0;
    for (double x : distances)
        sum += x;

    std::size_t siz{distances.size()};

    if(siz){
        std::cout << "Mean distances: " << sum / siz << '\n';

        // compute median temperature:
        std::sort(distances.begin(), distances.end()); //sort the distances

        std::cout << "Sorted Array: \n";
        for(auto itr : distances){
            std::cout << itr << ' ';
        }

        std::cout << '\n';
        std::cout << "Number of distances entered: " << siz << " \n";
        
        std::cout << "Smallest Distance between neighbouring cities = "<< *distances.begin() << '\n';
        std::cout << "Largest Distance between neighbouring cities = " << *(distances.end() - 1) << '\n';
    }

    return 0;
}