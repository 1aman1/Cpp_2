#include <iostream>
#include <thread>
#include <mutex>

std::mutex mtx;

void func()
{
    std::unique_lock<std::mutex> lock(mtx, std::defer_lock);

    // Perform some other operations here

    lock.lock(); // Explicitly acquire the lock
    for (int i = 1; i <= 10; ++i)
    {
        std::cout << i << " ";
    }

    std::cout << std::endl;
    lock.unlock(); // Explicitly release the lock

    // Perform some other operations here
}

int main()
{
    std::thread t(func);

    // Perform some other operations here

    t.join();

    return 0;
}
