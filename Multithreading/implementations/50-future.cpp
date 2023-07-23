#include <iostream>
#include <thread>
#include <future>

int sum(int a, int b)
{
    std::cout << "sum " << std::this_thread::get_id() << std::endl;
    return a + b;
}

int main()
{
    std::cout << "main " << std::this_thread::get_id() << std::endl;

    // creates new thread & executes
    std::future<int> result = std::async(std::launch::async, sum, 4, 5);

    // use deferred to execute when '*.get' is executed
    // keep same thread
    // std::future<int> result = std::async(std::launch::deferred, sum, 4, 5);

    // DO OTHER WORK CONCURRENTLY

    if (result.valid())
        std::cout << result.get() << std::endl; // Get the result when it becomes available

    if (result.valid())
        std::cout << result.get() << std::endl;
    else
        std::cout << "calls exhausted" << std::endl;

    return 0;
}
