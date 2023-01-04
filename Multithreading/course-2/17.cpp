#include <iostream>
#include <algorithm>
#include <vector>
#include <thread>
#include <chrono>
#include <mutex>
#include <future>

void thread_func(std::promise<int> &&promise, const int i)
{
    std::this_thread::sleep_for(std::chrono::seconds(2));
    promise.set_value(i * i);
}

int main()
{
    int var = 10;

    std::promise<int> promise;

    std::future<int> future = promise.get_future();

    std::thread t1(thread_func, std::move(promise), var);

    std::cout << "waiting\n";

    std::cout << future.get();

    t1.join();

    return 0;
}