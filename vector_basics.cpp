/**
 * @file vector_basics.cpp
 * @author Ivan Mercep
 * @brief
 * Basic std::vector operations
 * @version 0.1
 * @date 2021-09-06
 *
 * @copyright Copyright (c) 2021
 *
 */

#include <iostream>
#include <vector>

int main()
{
    std::vector<char> myVec = {'a', 'b', 'c'};
    std::vector<char>::iterator it;

    it = myVec.begin() + 2;
    myVec.insert(it, 'z'); // insert 'z' after 2 elements

    for (char value : myVec) // print
        std::cout << value << " ";
    std::cout << "\n === \n";

    myVec.erase(myVec.begin() + 1); // remove 2nd element

    for (char value : myVec) // print
        std::cout << value << " ";
    std::cout << "\n";

    return 0;
}