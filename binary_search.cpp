/**
 * @file binary_search.cpp
 * @author Ivan Mercep
 * @brief 
 * Binary search algorithm used to find data in the sorted array.
 * O(log(n))
 * @version 0.1
 * @date 2021-09-06
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <iostream>
#include <vector>

int binarySearch(int lowIndex, int highIndex, int value, const std::vector<int>& data)
{
    int midIndex = (int)(lowIndex + highIndex) / 2;

    if (data[midIndex] == value)
        return midIndex;
    if (lowIndex+1 == highIndex)
        return -1;
    if (value < data[midIndex])
        binarySearch(lowIndex, midIndex, value, data);
    else if (value > data[midIndex])
        binarySearch(midIndex, highIndex, value, data);
}

int main(int argc, char** argv)
{
    std::vector<int> data{1,3,5,7,9,11,13,15,17};
    //std::vector<int> data{1,2};
    int looking_for = 7;

    std::cout << "looking for: " << looking_for << "\n";
    std::cout << "input data: ";
    for(int num : data)
        std::cout << num << " ";

    std::cout << "\n" << binarySearch(0, data.size(), looking_for, data) << "\n";

    return 0;
}
