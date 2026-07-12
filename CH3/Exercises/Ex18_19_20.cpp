#include<iostream>
#include <string>
#include <array>
#include <algorithm>
#include <vector>
#include <math.h>


/*[18] Write a program where you first enter a set of name-and-value pairs, such as Joe 17 and Barbara
22. For each pair, add the name to a vector called names and the number to a vector
called scores (in corresponding positions, so that if names[7]=="Joe" then scores[7]==17).
Terminate input with NoName 0. Check that each name is unique and terminate with an error
message if a name is entered twice. Write out all the (name,score) pairs, one per line.

[19] Modify the program from the previous exercise so that once you have entered the name-andvalue
pairs, you ask for values: In a loop, when you enter a name, the program will output the
corresponding score or name not found.

[20] Modify the program from the previous exercise so that once you have entered the name-andvalue
pairs, you ask for names: In a loop, when you enter a value, the program will output all
the names with that score or score not found.*/

template <typename T>
T GetUserInput(){
    T user_in{};

    if(std::cin>>user_in){
        return user_in;        
    }

    throw (std::runtime_error("Wrong user input "));
}

static bool IsRepeatedName(const std::string name, const std::vector<std::string>& vecRef){
    if(vecRef.size()){
        for(auto iter : vecRef){
            if(name == iter){
                return true;
            }
        }
    }

    return false;
}

static void PrintVectorPairs(const std::vector<std::string>& vecNameRef, const std::vector<double> vecValRef){
    if(vecNameRef.size() > 0 && (vecNameRef.size() == vecValRef.size())){
        for(auto idx{0}; idx<vecNameRef.size(); idx++){
            std::cout << "Name: "<<vecNameRef[idx] << "\tVal: "<<vecValRef[idx]<<'\n';
        }
    }else{
        std::cout << "Nothing to show or not aligned data \n";
    }
    
}

static void ShowEquivalentScore(const std::string& nameRef, const std::vector<std::string>& vecNameRef, const std::vector<double> vecValRef){
    if(vecNameRef.size() > 0){
        if(vecNameRef.size() == vecValRef.size()){
            for(auto idx{0}; idx<vecNameRef.size(); idx++){
                if(nameRef == vecNameRef[idx]){
                    std::cout << "Score: " << vecValRef[idx] << '\n';
                    return;
                }
            }
            std::cout << "Name Not Found\n";
            return;
        }
        else{
            throw (std::runtime_error("Not aligned Vectors"));
        }
    }
    else{
        std::cout << "No Members in database\n";
    }
}

static void ShowNames(const double score, const std::vector<std::string>& vecNameRef, const std::vector<double> vecValRef){
    if(vecNameRef.size() > 0){
        if(vecNameRef.size() == vecValRef.size()){
            bool isFound{false};
            for(auto idx{0}; idx<vecNameRef.size(); idx++){
                if(score == vecValRef[idx]){
                    std::cout << vecNameRef[idx] << '\n';
                    isFound = true;
                }
            }
            if(!isFound){
                std::cout << "Score Not Found\n";
            }
        }
        else{
            throw (std::runtime_error("Not aligned Vectors"));
        }
    }
    else{
        std::cout << "No Members in database\n";
    }
}

std::vector<std::string> nameVec{};
std::vector<double> scoreVec{};



void Ex18(){
    while(1){
        std::cout << "Enter the NAME value pairs separated by space: ";
    
        std::string currName{GetUserInput<std::string>()};
        double currScore{GetUserInput<double>()};

        if(currName == "NoName" && currScore == 0){
            PrintVectorPairs(nameVec, scoreVec);
            break;
        }
        else if(IsRepeatedName(currName, nameVec)){
            std::cout << "name is entered twice \n";
            break;
        }
        else{
            nameVec.push_back(currName);
            scoreVec.push_back(currScore);
        }
    }
}

void Ex19(){
    while(1){
        std::cout<< "Enter Name to get equivalent score for: ";
        std::string name{GetUserInput<std::string>()};
        if(name == "q"){
            break;
        }
        ShowEquivalentScore(name, nameVec, scoreVec);
    }
}

void Ex20(){
    while(1){
        std::cout<< "Enter Score to be searched for: ";
        double score{GetUserInput<double>()};
        ShowNames(score, nameVec, scoreVec);
    }
}

int main()
{
    try{
        Ex18();
        Ex19();
        Ex20();
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return -1;
    }

    return 0;
}