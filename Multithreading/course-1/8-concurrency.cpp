#include <iostream>
#include <thread>

void thread_function()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

int main()
{
    std::cout << std::thread::hardware_concurrency() << std::endl;

    return 0;
}