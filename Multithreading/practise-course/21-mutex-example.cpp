#include <iostream>
#include <algorithm>
#include <vector>
#include <thread>
#include <chrono>
#include <mutex>

int wallet = 0;
std::mutex mtx;

void addMoney(int x)
{
    for (int i = 0; i < 100; ++i)
    {
        if (mtx.try_lock())
        {
            ++wallet;
            mtx.unlock();
        }
    }
}

int main()
{
    std::cout << wallet << "\n";

    std::thread t1(addMoney, 10);
    std::thread t2(addMoney, 10);

    std::cout << "pre main thread \n";

    if (t1.joinable())
        t1.join();
    if (t2.joinable())
        t2.join();

    std::cout << wallet << "\n";
    std::cout << "post main thread\n";
    
    return 0;
}
