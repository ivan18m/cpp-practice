/**
 * @file fibonacci.cpp
 * @author Ivan Mercep
 * @brief 
 * Fibonacci
 * @version 0.1
 * @date 2021-09-06
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <iostream>

/**
 * @brief 
 * Print all Fibonacci numbers from 0 to n
 * @param n 
 */
void printFib(int n) 
{
    int f = 1;
    int prev = 0;

    for(int i = 0; i < n; i++) {
        std::cout << i+1 << ": " << f << "\n";
        f = f + prev;
        prev = f - prev;
    }
}

/**
 * @brief 
 * Recursive way. O(2^n)
 * @param n 
 * @return int n-th Fibonacci number
 */
int findFibRecursive(int n) 
{
    if(n == 0 || n == 1)
        return n;
    return findFibRecursive(n-1) + findFibRecursive(n-2);
}

/**
 * @brief 
 * Iterative way. O(n)
 * @param n 
 * @return int n-th Fibonacci number
 */
int findFibIterative(int n) 
{
    int f = 1;
    int prev = 0;

    for(int i = 1; i < n; i++) 
    {
        f = f + prev;
        prev = f - prev;
    }
    return f;
}

int main() 
{
    int n;

    std::cout << "Enter a number: ";
    std::cin >> n;

    printFib(n);

    std::cout << "Fibonacci number is: " << findFibRecursive(n) << "\n";
    std::cout << "Fibonacci number is: " << findFibIterative(n) << "\n";

    return 0;
}