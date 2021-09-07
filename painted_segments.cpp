/**
 * @file painted_segments.cpp
 * @author Ivan Mercep
 * @brief 
 * Given the infinite line determine how many "painting" operations will be done
 * on it's segments. Segments that are already painted don't need to get painted 
 * again in the next iteration
 * 
 * Example:
 *         ---1---2---3---4---5---6---7---8---9---10---
 * [1,5]      |___________|
 * [3,6]              |_______|
 * [7,10]                             |_______|
 * [1,9]      |___________________________|
 *
 * Output: [4, 1, 3, 1]
 * 
 * @version 0.1
 * @date 2021-09-07
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <iostream>
#include <vector>
#include <unordered_set>

// TODO: optimized solution with merging of overlapped pairs

/**
 * @brief Get the number of painted segments in a vector
 * time complexity: O(n*n) solution where n is number of pairs
 * space complexity: O(m) where m is the range
 * 
 * @param input vector of given range pairs
 * @return std::vector<int> container with number of painted segs for each range
 */
std::vector<int> getPaintedSegs(std::vector<std::pair<int, int>>& input)
{
    std::unordered_set<int> paintedSegs;
    std::vector<int> numsOfPaintedSegs;

    for(std::pair<int, int> p : input)
    {
        int count = paintedSegs.size();
        for(int i = p.first; i < p.second; i++)
            paintedSegs.insert(i);
        numsOfPaintedSegs.push_back(paintedSegs.size() - count);
    }
    return numsOfPaintedSegs;
}

int main(int argc, char** argv)
{
    std::vector<std::pair<int, int>> input {{1,5}, {3,6}, {7,10}, {1,9}};
    std::cout << "Input: ";
    for(auto p : input) 
        std::cout << "[" << p.first << "-" << p.second << "] ";
    std::cout << "\n";

    std::vector<int> output = getPaintedSegs(input);
    std::cout << "Number of painted segments: ";
    for(int num : output) 
        std::cout << num << " ";
    std::cout << "\n";
    return 0;
}