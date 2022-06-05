#include <iostream>
#include <thread>

void thread_function()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

int main()
{
    std::thread t(thread_function);

    // std::thread t2 = t;
    std::thread t2 = move(t);

    if (t2.joinable())
        t2.join();
        
    return 0;
}