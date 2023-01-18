#include <iostream>
#include <algorithm>
#include <vector>
#include <thread>
#include <chrono>
#include <mutex>

struct Base
{
    int wallet = 0;
    std::mutex mtx;

    void addMoney(int x)
    {
        if (mtx.try_lock())
        {
            wallet += x;
            mtx.unlock();
        }
    }
};

int main()
{
    Base obj;

    std::cout << "wallet amount " << obj.wallet << "\n";

    std::thread T(&Base::addMoney, &obj, 200);

    if (T.joinable())
        T.join();

    std::cout << "wallet amount " << obj.wallet << "\n";

    return 0;
}
