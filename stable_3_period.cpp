/**
 * @file stable_3_period.cpp
 * @author Ivan Mercep
 * @brief 
 * You have measured position of the particle in N equally distributed moments.
 * The measurement made in moment i is recorded in array A as A[i].
 * Count all periods of time when the movement of the particle was stable.
 * Those are the periods during which the particle doesn't change it's velocity.
 * Note that you need at least three measurements to be sure 
 * that the particle didn't change it's velocity.
 * 
 * Example:
 * [1, 3, 5, 7, 9] is stable (velocity is 2)
 * [7, 7, 7, 7]    is stable (velocity is 2)
 * [3, -1, -5, -9] is stable (velocity is -4)
 * [0, 1]          is not stable (need at least 3 measurements)
 * [1, 1, 2, 5, 7] is not stable (velocity changes beween measurements)
 * 
 * Given the array of N integers representing results of measurements, 
 * return the number of periods when the movement of the particle was stable.
 * 
 * Example:
 * [-1, 1, 3, 3, 3, 2, 3, 2, 1, 0] the function should return 5, 
 * because there are 5 periods during which the movement of the particle was stable:
 * (0,2), (2,4), (6,9), (6,8) and (7,9). 
 * Note that last 2 periods are contained by (6,9)
 * 
 * @version 0.1
 * @date 2021-09-06
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <iostream>
#include <vector>

/**
 * @brief 
 * Iterate the vector
 * Check if period is stable for each element
 * O(n*n) solution
 * @param A 
 * @return int Number of stable periods in input
 */
int solution(const std::vector<int>& A) 
{
    int numOfStablePeriods = 0;
    for (uint32_t i = 0; i < A.size(); ++i) 
    {
        for (uint32_t count = 0; i < A.size()-2; ++i) 
        {
            bool isStable = A[i+1] - A[i] == A[i+2] - A[i+1];
            if(!isStable)
                break;
            
            count++;
            numOfStablePeriods += count;
        }
    }
    return numOfStablePeriods;
} 

int main(int argc, char** argv)
{
    std::vector input {1, 1, 1, 2, 3, 4, 5};
    std::cout << "Input: ";
    for(int num : input)
        std::cout << num << " ";
    std::cout << "\n";
    std::cout << solution(input);
    return 0;
}
