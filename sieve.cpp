/**
 * @file sieve.cpp
 * @author Ivan Mercep
 * @brief
 * Sieve of Eratosthenes algorithm to find prime numbers until n
 * @version 0.1
 * @date 2021-09-06
 *
 * @copyright Copyright (c) 2021
 *
 */

#include <iostream>
#include <vector>

void sieve(int n)
{
    std::vector<bool> isPrime(n, true);

    // Iterate through container. (i*i < n) same as (i < sqrt(n))
    for (int i = 2; i * i < n; ++i)
    {
        if (isPrime[i])
        {
            // Set everything to false that can be divided with this number (i)
            // i*2..*3..*4 is false
            for (int j = i * 2; j < n; j += i)
                isPrime[j] = false;
        }
    }

    std::cout << "Prime numbers are: ";
    for (int i = 2; i < n; i++)
    {
        if (isPrime[i])
            std::cout << i << " ";
    }
    std::cout << "\n";
}

int main(int argc, char **argv)
{
    int n;
    std::cout << "This program finds first n prime numbers\n";
    std::cout << "Enter a n: ";
    std::cin >> n;
    sieve(n);
    return 0;
}
