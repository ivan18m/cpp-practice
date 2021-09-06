#include <iostream>
#include <unordered_map>

bool areBalanced(const std::string& s) 
{
    std::string open;
    std::unordered_map<char, char> opposite 
    {
        {'(', ')'},
        {'[', ']'},
        {'{', '}'}
    };

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