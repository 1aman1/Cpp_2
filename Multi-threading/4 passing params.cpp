#include <iostream>
#include <thread>

void thread_function(int x)
{
    std::cout << __PRETTY_FUNCTION__ << x << std::endl;
}

int main()
{
    int x = 100;
    std::thread t(thread_function, x);

    if (t.joinable())
        t.join();
        
    return 0;
}
