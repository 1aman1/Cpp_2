#include <iostream>
#include <algorithm>
#include <vector>
#include <thread>
#include <chrono>
#include <mutex>

struct Solution
{
    int wallet = 0;
    std::mutex mtx;

    void addMoney(int x)
    {
        mtx.lock();
        ++wallet;
        mtx.unlock();
        std::cout << x << " thread was here\n";
    }
};

int main()
{
    Solution obj;

    std::cout << obj.wallet << "\n";

    std::thread t1(&Solution::addMoney, &obj, 8);
    std::cout << "pre main thread \n";

    if (t1.joinable())
        t1.join();

    std::cout << obj.wallet << "\n";
    std::cout << "post main thread\n";
    return 0;
}
