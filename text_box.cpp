/**
 * @file text_box.cpp
 * @author Ivan Mercep
 * @brief
 * Text box is used to send the input.
 * When the user types backspace it's appended to the string.
 * Given such string with appended backspaces write an algorithm
 * that outputs the text where backspace deletes the previous char
 *
 * @version 0.1
 * @date 2021-09-07
 *
 * @copyright Copyright (c) 2021
 *
 */

#include <iostream>
#include <string>

std::string parseString(const std::string &input, const char sym = '\b')
{
    std::string output = "";

    for (char c : input)
    {
        if (c != sym)
            output.push_back(c);
        else
            output.pop_back();
    }

    return output;
}

bool compareStrings(const std::string &str1, const std::string &str2, const char &sym)
{
    return parseString(str1, sym) == parseString(str2, sym);
}

int main(int argc, char **argv)
{
    const std::string str1 = "abb0cdee0f";
    const std::string str2 = "abcdee0f";
    const char sym = '0'; // in this case 0 is backspace

    std::cout << "First string: " << str1 << "\n";
    std::cout << "Second string: " << str2 << "\n";
    std::cout << "Strings are the same: " << compareStrings(str1, str2, sym) << "\n";

    return 0;
}