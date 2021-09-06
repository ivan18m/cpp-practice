/**
 * @file threading.cpp
 * @author Ivan Mercep
 * @brief 
 * Basic execution of function in seperate thread
 * @version 0.1
 * @date 2021-09-06
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <iostream>
#include <thread>
#include <chrono>

void someFunc(std::string name) 
{
    while(true) 
    {
        std::cout << "Thread: " << name << "\n";
        std::this_thread::sleep_for(std::chrono::seconds(2));
    }
}

int main(int argc, char** argv) 
{
    std::thread first(someFunc, "FIRST THREAD");
    std::thread second(someFunc, "SECOND THREAD");

    while(true) 
    {
        std::cout  << "\n  === IN MAIN === \n";
        std::this_thread::sleep_for(std::chrono::seconds(5));
    }

    first.join(); // Execution of the main thread pauses and waits until the first thread ends
    second.detach(); // Creates seperate process, execution main thread continues running

    return 0;
}
