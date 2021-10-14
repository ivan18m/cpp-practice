/**
 * @file compare_array_data.cpp
 * @author Ivan Mercep (you@domain.com)
 * @brief
 * Compare if 2 arrays contain the same data
 * @version 0.1
 * @date 2021-09-05
 *
 * @copyright Copyright (c) 2021
 *
 */

#include <iostream>
#include <vector>
#include <unordered_map>

template<class T>
std::unordered_map<T, int> load_map(const std::vector<T> &data)
{
    std::unordered_map<T, int> data_freq;

    for (T elem : data)
        data_freq[elem]++;

    return data_freq;
}

// && is right value reference because we don't store load_map functions to variable (left value)
template<class T>
bool compare_maps(std::unordered_map<T, int> &&map1, std::unordered_map<T, int> &&map2)
{
    if (map1.size() != map2.size())
        return false;

    for (std::pair<T, int> pair : map1) // can just use "auto pair"
    {
        if (map1[pair.first] != map2[pair.first])
            return false;
    }

    return true;
}

int main(int argc, char **argv)
{
    std::vector<char> data1{'a', 'b', 'c'};
    std::vector<char> data2{'a', 'b', 'c'};

    bool result = compare_maps(load_map(data1), load_map(data2));

    std::cout << "Data is same: " << result << "\n";

    return 0;
}