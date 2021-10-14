/**
 * @file first_non_repeating.cpp
 * @author Ivan Mercep
 * @brief
 * algorithm saves frequency of a char in hash map
 * 2nd loop iterates string and checks where frequency == 1
 * 2 loops is O(2n) time complexity
 * @version 0.1
 * @date 2021-09-05
 *
 * @copyright Copyright (c) 2021
 *
 *
 */

#include <iostream>
#include <string>
#include <unordered_map>

char first_non_repeating_char(const std::string &input)
{
    std::unordered_map<char, int> seen_chars;

    for (char ch : input)
        seen_chars[ch]++;

    for (char ch : input)
    {
        if (seen_chars[ch] == 1) // O(1) find
            return ch;
    }

    return '-';
}

int main(int argc, char **argv)
{
    std::string str = "aabbcdddf";
    std::cout << "String: " << str << "\n";
    std::cout << "First non repeating char: " << first_non_repeating_char(str) << "\n";

    return 0;
}
