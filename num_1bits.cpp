/**
 * @file num_1bits.cpp
 * @author Ivan Mercep
 * @brief 
 * Given 2 non-negative integers, return the number of bits set to 1
 * in the binary representation of the number A * B
 * 
 * Example:
 * A=3, B=7, the function should return 3,
 * because the binary representation of A*B = 3*7 = 21 is 10101
 * and it contains three bits set to 1
 * 
 * @version 0.1
 * @date 2021-09-06
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <iostream>

 /**
  * @brief 
  * Count number of 1s in bits
  * Shift bits to right
  * Compare number AND 1 (00001)
  * countOneBits takes right value reference
  * O(32)
  * @param n the unsigned input 
  * @return uint32_t number of bits with 1
  */
uint32_t countOneBits(uint32_t&& n) 
{ 
    uint32_t count = 0; 
    while (n) { 
        count += n & 1; 
        n >>= 1; 
    } 
    return count; 
} 

/**
 * @brief 
 * Pass right value reference of A * B to coutOneBits
 * @param A 
 * @param B 
 * @return uint32_t 
 */
uint32_t solution(int A, int B) {
    return countOneBits(A * B);
} 

int main(int argc, char** argv)
{
    int A = 3;
    int B = 7;
    std::cout << "A: " << A << "\n";
    std::cout << "B: " << B << "\n";
    std::cout << "Output: " << solution(A, B) << "\n";
    return 0;
}
