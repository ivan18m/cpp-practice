/**
 * @file balanced_brackets.cpp
 * @author your name (you@domain.com)
 * @brief
 * Solution for the balanced brackets problem using a stack
 * @version 0.1
 * @date 2021-09-06
 *
 * @copyright Copyright (c) 2021
 *
 */

#include <iostream>
#include <unordered_map>

bool areBalanced(const std::string &s)
{
    std::string open;
    std::unordered_map<char, char> opposite{{'(', ')'}, {'[', ']'}, {'{', '}'}};

    for (char c : s)
    {
        if (c == '(' || c == '[' || c == '{')
            open.push_back(c);
        else if (c == opposite[open.back()])
            open.pop_back();
        else
            return false;
    }
    return open.empty();
}

int main()
{
    std::string s = "{[()]}()";
    std::cout << "The string: " << s << " \n";
    std::cout << "Balanced: " << areBalanced(s) << "\n";
    return 0;
}