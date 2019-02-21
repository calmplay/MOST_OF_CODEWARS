#pragma once
#include<iostream>
#include <vector>
#include <algorithm>

//■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■
//KATA1:Find the odd int
/*-------------------------------------------------------------
Given an array, find the int that appears an odd number of times.

There will always be only one integer that appears an odd number of times.

理解：给出一个数组中，只有一个数是出现奇数次，找出它！

FOR EXAMPLE:

using V = std::vector<int>;

Describe(FindOdd){
It(BasicTests){
Assert::That(findOdd(V{20,1,-1,2,-2,3,3,5,5,1,2,4,20,4,-1,-2,5}), Equals(5));
Assert::That(findOdd(V{1,1,2,-2,5,2,4,4,-1,-2,5}), Equals(-1));
Assert::That(findOdd(V{20,1,1,2,2,3,3,5,5,4,20,4,5}), Equals(5));
Assert::That(findOdd(V{10}), Equals(10));
Assert::That(findOdd(V{1,1,1,1,1,1,10,1,1,1,1}), Equals(10));
}
};

*/


//my function

int findOdd(const std::vector<int>& numbers)
{
    std::vector<int> temp_arr = numbers;
    std::sort(temp_arr.begin(), temp_arr.end());
    int last_num = 0;
    for (auto n : temp_arr)
    {
        last_num += (last_num>0?(-1)*n:n);
    }
    return last_num;
}

//the best function


std::vector<int> numbers[5];


//■■■■■■■■■MAIN_TEST
void main_test()
{
    numbers[0] = { 20, 1, -1, 2, -2, 3, 3, 5, 5, 1, 2, 4, 20, 4, -1, -2, 5 };
    numbers[1] = { 1, 1, 2, -2, 5, 2, 4, 4, -1, -2, 5 };
    numbers[2] = { 20, 1, 1, 2, 2, 3, 3, 5, 5, 4, 20, 4, 5 };
    numbers[3] = { 10 };
    numbers[4] = { 1, 1, 1, 1, 1, 1, 10, 1, 1, 1, 1 };

    for (int i = 0; i < 5; i++)
    {
        std::cout << "numbers"<<i+1<<":";
        for (auto n : numbers[i])
        {
            std::cout << n<<",";
        }
        std::cout <<"\n"<<"——> "<< findOdd(numbers[i]);
        std::cout << std::endl;
    }
   

  
    system("PAUSE");//等待功能

}
