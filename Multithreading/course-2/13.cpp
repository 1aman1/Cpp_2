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
    std::unique_lock<std::mutex> lock(mtx);
    ++wallet;
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << x << " acquired lock\n";
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
