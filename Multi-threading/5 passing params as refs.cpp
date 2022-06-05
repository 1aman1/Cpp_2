#include <iostream>
#include <thread>
#include <chrono>

void thread_function(int x)
{
    std::cout << __PRETTY_FUNCTION__ << x << std::endl;
    x = 200;
}

int main()
{
    int x = 100;

    // reference has to be explicit, in calling function also
    std::thread t(&thread_function, std::move(x));

    if (t.joinable())
        t.join();

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    std::cout << x << std::endl;

    return 0;
}
