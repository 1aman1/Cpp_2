#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

constexpr int TotalNumbers = 10;

std::mutex mtx;
std::condition_variable cv;
int counter = 1;

void thread1Function()
{
    for (int i = 0; i < TotalNumbers; i += 2)
    {
        std::unique_lock<std::mutex> lock(mtx);

        cv.wait(lock, []
                { return counter & 1 ? 1 : 0; });

        std::cout << "Thread 1: " << counter++ << std::endl;

        lock.unlock();
        cv.notify_all();
    }
}

void thread2Function()
{
    for (int i = 1; i < TotalNumbers; i += 2)
    {
        std::unique_lock<std::mutex> lock(mtx);

        cv.wait(lock, []
                { return counter & 1 ? 0 : 1; });

        std::cout << "Thread 2: " << counter++ << std::endl;

        lock.unlock();
        cv.notify_all();
    }
}

int main()
{
    std::thread thread1(thread1Function);
    std::thread thread2(thread2Function);

    thread1.join();
    thread2.join();

    return 0;
}
