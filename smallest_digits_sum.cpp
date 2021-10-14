/**
 * @file smallest_digits_sum.cpp
 * @author Ivan Mercep
 * @brief
 * Write a function that, given integer N,
 * returns the smallest non-negative integer whose individual digits sum to N.
 *
 * Examples:
 * N = 16, the function should return 79.
 * There are many numbers whose digits sum to 16 (79, 97, 808...).
 * The smallest is 79
 * N = 19, the function should return 199.
 *
 * Assume that N is an integer withing [0..50]
 *
 * @version 0.1
 * @date 2021-09-06
 *
 * @copyright Copyright (c) 2021
 *
 */
#include <iostream>

int solution(int N)
{
    int min = 0;
    int max = 50;

    if (N < min || N > max)
        return 0;

    if (N / 10 == 0)
        return N;

    // 19 is lowest number which gives 2 digit sum
    // Smallest number always has last digit = 9
    int i = 19;
    int increment = 10;

    // Optimize search for N [19-50]
    if (N >= 19 && N < 28)
    {
        i = 199;
        increment = 100;
    }
    else if (N >= 28 && N < 37)
    {
        i = 1999;
        increment = 1000;
    }
    else if (N >= 37 && N < 46)
    {
        i = 19999;
        increment = 10000;
    }
    else if (N >= 46 && N <= 50)
    {
        i = 199999;
        increment = 100000;
    }

    while (true)
    {
        int temp = i;
        int sum = 0;
        // Check sum of digits
        while (temp > 0)
        {
            sum += temp % 10;
            temp /= 10;
        }

        if (sum == N)
            return i;

        i += increment;
    }
}

int main(int argc, char **argv)
{
    int input = 19;
    std::cout << "Input: " << input << "\n";
    std::cout << "Output: " << solution(input) << "\n";
    return 0;
}
