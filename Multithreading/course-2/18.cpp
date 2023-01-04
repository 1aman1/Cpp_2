#include <iostream>
#include <algorithm>
#include <vector>
#include <thread>
#include <chrono>
#include <mutex>
#include <future>

int thread_func(const int i)
{
    std::cout << " thread with ID : "
              << std::this_thread::get_id()
              << "\n";
    std::this_thread::sleep_for(std::chrono::seconds(2));
    return i * i;
}

int main()
{
    int var = 10;

    std::cout << " thread with ID : "
              << std::this_thread::get_id()
              << "\n";

    // keep same thread
    std::future<int> future = std::async(std::launch::deferred, thread_func, 2);

    // create new thread
    // std::future<int> future = std::async(std::launch::async, thread_func, 2);

    std::cout << "waiting\n";

    std::cout << future.get();

    // t1.join();

    return 0;
}