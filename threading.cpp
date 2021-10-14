/**
 * @file threading.cpp
 * @author Ivan Mercep
 * @brief
 * Basic execution of function in seperate thread
 * Usage of mutex, lock guard and an atomic variable
 * @version 0.1
 * @date 2021-09-06
 *
 * @copyright Copyright (c) 2021
 *
 */

#include <atomic>
#include <chrono>
#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

std::atomic<int> atomic_counter(0);
std::vector<int> myVec;
std::mutex m;

void someFunc(const std::string &name)
{
    while (true)
    {
        ++atomic_counter;
        std::cout << "Thread: " << name << "\n";
        std::cout << "atomic_counter: " << atomic_counter << "\n";

        std::lock_guard<std::mutex> lock(m);
        myVec.push_back(atomic_counter);
        std::cout << "vec size: " << myVec.size() << "\n";

        std::this_thread::sleep_for(std::chrono::seconds(1)); // sleep doesn not unlock mutex
    }
}

int main(int argc, char *argv[])
{
    std::thread first(someFunc, "FIRST THREAD");
    std::thread second(someFunc, "SECOND THREAD");

    while (true)
    {
        std::cout << "\n  === IN MAIN === \n";
        ++atomic_counter;
        std::cout << "atomic_counter: " << atomic_counter << "\n";

        std::lock_guard<std::mutex> lock(m);
        myVec.push_back(atomic_counter);
        std::cout << "vec size: " << myVec.size() << "\n";

        std::this_thread::sleep_for(std::chrono::seconds(1)); // sleep does not unlock mutex
    }

    first.join();    // Execution of the main thread pauses and waits until the first thread ends
    second.detach(); // Creates seperate process, execution main thread continues running

    return 0;
}
