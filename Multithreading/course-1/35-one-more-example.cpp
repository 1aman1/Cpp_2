#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <vector>
/*
a std::cout resource fight goes here, on each executio the output comesout different.
*/

std::mutex mu;
std::vector<int> myVec;

void thread_function(int m, int n)
{
    for (int i = m; i < n; i++)
        myVec.push_back(i);
}

void print()
{
    for (auto i : myVec)
        std::cout << i << std::endl;
}

int main()
{
    std::thread t1(thread_function, 10, 20);
    std::thread t2(thread_function, 80, 90);
    std::thread t3(print);

    std::this_thread::sleep_for(std::chrono::milliseconds(200));

    t1.join();
    t2.join();
    t3.join();

    std::cout << "main thread \n";

    return 0;
}