#include <iostream>
#include <algorithm>
#include <vector>
#include <thread>
#include <chrono>
#include <mutex>

int wallet = 0;
std::timed_mutex mtx;

void addMoney(int x)
{
    if (mtx.try_lock_for(std::chrono::seconds(1)))
    {
        ++wallet;
        std::this_thread::sleep_for(std::chrono::seconds(2));
        std::cout << x << " acquired lock\n";
        mtx.unlock();
    }
    else
        std::cout << "couldnt lock\n";
}

int main()
{
    std::thread t1(addMoney, 1);
    std::thread t2(addMoney, 2);

    std::cout << "pre main thread \n";

    if (t1.joinable())
        t1.join();
    if (t2.joinable())
        t2.join();

    std::cout << wallet << " wallet\n";
    std::cout << "post main thread\n";
    return 0;
}
