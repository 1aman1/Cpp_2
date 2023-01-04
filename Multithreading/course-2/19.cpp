#include <iostream>
#include <algorithm>
#include <queue>
#include <thread>
#include <chrono>
#include <mutex>
#include <future>

std::mutex mtx;
std::condition_variable cv;
std::queue<int> buffer;
constexpr int SIZE = 50;

void producer(int units)
{
    while (units)
    {
        std::unique_lock<std::mutex> ul(mtx);
        cv.wait(ul, []()
                { return buffer.size() < SIZE; });

        buffer.push(units);
        std::cout << "producer pushed " << units-- << "\n";
        ul.unlock();
        cv.notify_one();
    }
    std::cout << "producer quit\n";
}

void consumer()
{
    while (true)
    {
        std::unique_lock<std::mutex> ul(mtx);
        cv.wait(ul, []()
                { return buffer.size() > 0; });
        int data = buffer.front();
        buffer.pop();
        std::cout << "consumed " << data << "\n";
        ul.unlock();
        cv.notify_one();
    }
}

int main()
{
    std::thread t1(producer, 10);
    std::thread t2(consumer);

    if (t1.joinable())
        t1.join();
    if (t2.joinable())
        t2.join();

    return 0;
}