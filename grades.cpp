/**
 * @file grades.cpp
 * @author Ivan Mercep
 * @brief 
 * Every student receives a grade in the inclusive range from 0 to 100.
 * Any grade less than 40 is a failing grade.
 * Sam is a professor at the university and likes to round each student's grade according to these rules:
 *   - If the difference between the grade and the next multiple of 5 is less than 3, round grade up to the next multiple of 5.
 *   - If the value of grade is less than 38, no rounding occurs as the result will still be a failing grade.
 *
 * @version 0.1
 * @date 2021-09-06
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <iostream>
#include <vector>

std::vector<int> roundGrades(const std::vector<int>& grades)
{
    std::vector<int> newGrades;
    for(int grade : grades)
    {
        int diff = 5 - grade % 5;
        if(grade < 38)
        {
            newGrades.push_back(grade);
            continue;
        }
        if(diff < 3)
            grade += diff;
        newGrades.push_back(grade);
    }
    return newGrades;
}

int main()
{
    std::vector<int> grades {37, 38, 40, 78, 81};
    std::vector<int> newGrades = roundGrades(grades);
    for(int grade : newGrades) 
    {
        std::cout << grade << " ";
    }
    std::cout << "\n";
    return 0;
}