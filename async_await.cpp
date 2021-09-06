/**
 * @file async_await.cpp
 * @author Ivan Mercep
 * @brief 
 * The example of async await multithreading
 * @version 0.1
 * @date 2021-09-06
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <iostream>
#include <thread>
#include <chrono>
#include <future>

int someFunc() 
{
    int i = 0;
    while(i < 5) 
    {
        i++;
        //std::cout << "blabla\n";
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    return i;
}

int main(int argc, char** argv) 
{
    std::future<int> result_future = std::async(someFunc);
    std::cout << "wait...\n";
    result_future.wait(); // wait for result_future to receive data (int)
    std::cout << result_future.get() << "\n";

    return 0;
}
