/**
 * @file greatest_common_devisor.cpp
 * @author Ivan Mercep
 * @brief 
 * Greatest Common Divisor (GCD) also called Highest Common Factor (HCF) of N numbers
 * is the largest positive integer that divides all numbers without giving a remainder.
 * 
 * Algorithm to determine GCD of N positive integers.
 * 
 * Example input:
 * num = 5
 * arr = [2, 4, 6, 8, 10]
 * 
 * Example output: 2
 * Because the largest positive integer that divides all 
 * integers in the array without a remainder is 2
 * 
 * @version 0.1
 * @date 2021-09-06
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <iostream>

int gcdFrom2(int first, int second)
{
    int tmp;
    while(second > 0)
    {
        tmp = second;
        second = first % second;
        first = tmp;
    }
    return first;
}

int GCD(int num, int* arr)
{
    int value = *arr;

    for(int i = 0; i < num; i++)
    {
        if(*arr == 1)
            return 1;
        value = gcdFrom2(value, *(arr+i));
    }
    return value;
}

int main(int argc, char** argv)
{
    int num = 5;
    int* arr = new int[num];

    // Fill in array
    for(int i = 0; i < num; i++)
    {
        if(i*i % 2 == 0)
            *(arr+i) = i*i+4;
        else
            *(arr+i) = i*i+3;
    }
    
    std::cout << "Input: ";
    for(int i = 0; i < num; i++)
        std::cout << *(arr+i) << " ";
    std::cout << "\n";

    std::cout << "GCD: " << GCD(num, arr) << "\n";

    delete arr;
    return 0;
}