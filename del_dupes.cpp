/**
 * @file del_dupes.cpp
 * @author Ivan Mercep (you@domain.com)
 * @brief 
 * Delete duplicate characters from the string
 * @version 0.1
 * @date 2021-09-05
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <iostream>
#include <set>
#include <unordered_map>
#include <string>

// O(2n) == O(n)
std::string delDupesAndSort(const std::string& str) 
{
    std::set<char> strSet;
    std::string newStr = "";
    
    // insert chars in a std::set (it's always sorted)
    for(const char c : str) 
        strSet.insert(c);
    
    // return them in a std::string
    for(const char c : strSet) 
        newStr.push_back(c);
    
    return newStr;
}

// O(n*n)
// std::string delDupes(const std::string& str) 
// {
//     std::string newStr = "";
    
//     for(const char c : str)
//     {
//         if(newStr.find(c) >= newStr.length()) // find is O(n)
//             newStr.push_back(c);
//     }
    
//     return newStr;
// }

// O(2n) == O(n)
std::string delDupes(const std::string& str) 
{
    std::unordered_map<char, bool> char_used;
    std::string newStr = "";

    for(const char c : str)
        char_used[c] = true;
    
    for(const char c : str)
    {
        if(char_used[c])
        {
            newStr += c;
            char_used[c] = false;
        } 
    }
    
    return newStr;
}

int main(int argc, char** argv) 
{
    std::string a = "cccccbbaaazaaaaaaa";
    std::cout << "String: " << a << "\n";
    std::cout << "Delete duplicates and sort: " << delDupesAndSort(a) << "\n";
    std::cout << "Delete duplicates: " << delDupes(a) << "\n";
    return 0;
}
