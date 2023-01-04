#include <iostream>
#include <thread>

int main()
{
    std::thread t([]()
                  { std::cout << "thread function\n"; });
    t.join(); // main thread waits for t to finish
    std::cout << "main thread\n";

    return 0;
}