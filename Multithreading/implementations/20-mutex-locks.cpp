#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <map>
#include <bitset>
#include <mutex>
#include <thread>
#include <chrono>

std::mutex mtx1;
std::mutex mtx2;

void tfun1(int x)
{
    mtx1.lock();
    mtx2.lock();
    std::cout << "task 1\n";
    // std::this_thread::sleep_for(std::chrono::seconds(3));
    mtx1.unlock();
    mtx2.unlock();
}

void tfun2(int x)
{
    mtx2.lock();
    mtx1.lock();
    // std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "task 2\n";
    mtx2.unlock();
    mtx1.unlock();
}

int main()
{

    std::thread t1(tfun1, 1);
    std::thread t2(tfun2, 2);

    if (t1.joinable())
        t1.join();
    if (t2.joinable())
        t2.join();

    return 0;
}
