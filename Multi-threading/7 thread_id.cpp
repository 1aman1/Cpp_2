#include <iostream>
#include <thread>

void thread_function()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

int main()
{
    std::thread t(thread_function);

    std::cout << std::this_thread::get_id() << std::endl;

    if (t.joinable())
        t.join();

    return 0;
}