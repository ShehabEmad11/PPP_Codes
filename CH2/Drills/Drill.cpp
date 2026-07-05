#include<iostream>
#include <string>


int main()
{
    //Drill 1
    std::cout << "Enter the name of the person you want to write to:\n";
    std::string first_name; // first_name is a var iable of type string
    std::cin >> first_name; // read characters into first_name
    std::cout << "Dear " << first_name << ",\n";
    
    //Drill 2
    std::cout << "\tHow are you? I am fine. I miss you. I hope you are doing well.\n";
    std::cout << "I am writing this letter to you to tell you that I am learning C++ programming language.\n";

    //Drill 3
    std::string friend_name{};
    std::cout << "Enter Friend's name:\n";
    std::cin >> friend_name;
    std::cout << "Have you seen " << friend_name << " lately?\n";

    //Drill 4
    std::cout << "Enter the age of the recipient:\n";
    int age{};
    std::cin >> age;
    while(age <=0 || age>=110){
        std::cout <<"You are kidding! please enter a valid age.\n";
        std::cin >> age;
    }

    //Drill 5
    if(age < 12){
        std::cout << "Next year you will be " << age + 1 << ".\n";
    }
    else if(age == 17){
        std::cout << "Next year you will be able to vote.\n";
    }
    else if(age > 70){
        std::cout << "Are you retired?\n";
    }

    //Drill 6
    std::cout << "Yours sincerely,\n\n\n";
    std::cout << "Shehab\n";

    

}