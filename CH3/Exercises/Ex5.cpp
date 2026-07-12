#include<iostream>
#include <string>
#include <array>
#include <algorithm>
#include <vector>


/*[5]Write a program to play a numbers guessing game. The user thinks of a number between 1
and 100 and your program asks questions to figure out what the number is (e.g., ‘‘Is the number
you are thinking of less than 50?’’). Your program should be able to identify the number
after asking no more than seven questions.*/


static char GetUserInput_yn(){
    char user_in{};

    if(std::cin>>user_in){
        if(user_in == 'y' || user_in == 'n'){
            return user_in;
        }
    }

    throw (std::runtime_error("Wrong user input "));
}

static void GuessNum()
{
    std::cout << "Enter Number between 1 and 100: \n";
    int act_num{}, guessed_num{};
    int num_guesses{7};

    if(std::cin >> act_num){
        if ((act_num >= 1) && (act_num <= 100)){
            int temp_cntr{};
        
            /*Create 1->100 Vector*/
            std::vector<int> nums_list{};
            for(int i{1}; i<=100;i++){
                nums_list.push_back(i);
            }

            while(1)
            {
                std::size_t siz{nums_list.size()};

                if(siz == 0){
                    std::cout <<"Error\n";
                    throw(std::runtime_error("Over-Resizing array logic error\n"));
                }
                else if(siz == 1){
                    guessed_num = nums_list[0];
                    std::cout << "Guessed number is " << guessed_num << '\n';
                    break;
                }
                else if(num_guesses == 0){
                    break;
                }
                else
                {
                    std::cout << "Guess ID = " << ++  temp_cntr << ": \n";
                    std::cout << "--------Is Number less than " << nums_list[siz/2] << "? press 'y' or 'n' ?: ";
                    num_guesses--;

                    
                    char user_ans{GetUserInput_yn()};

                    std::size_t newSize{}, offset{};

                    if(siz % 2 == 0){   //Even size e.g 6 bytes
                        if(user_ans == 'y'){
                            offset = 0;
                            newSize = siz/2;
                        }else{
                            offset = siz/2;
                            newSize = siz/2;
                        }
                    }else{      //odd size e.g 5 bytes
                        if(user_ans == 'y'){
                            offset = 0;
                            newSize = siz/2;
                        }else{
                            offset = siz/2;
                            newSize = siz/2 + 1;                
                        }
                    }

                    std::vector<int> temp_vec(newSize);
                    std::copy_n(nums_list.begin() + offset, newSize, temp_vec.begin());
                    nums_list.resize(newSize);
                    std::copy_n(temp_vec.begin(), newSize, nums_list.begin());

                }
            }

            if(guessed_num == act_num){
                std::cout << "Correct Guess!\n";
            }
            else if (num_guesses == 0){
                std::cout << "Couldn't guess :( \n";
            }
            else
            {
                throw(std::runtime_error("un handled situation"));
            }
        }
        else
        {   
            std::cout << "Invalid user input.... range is only [1,100]\n";
            return;
        }
    }
    else{
        throw(std::runtime_error("Invalid CIN input\n"));
    }

}

int main()
{
    try{
        GuessNum();
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return -1;
    }

    return 0;
}