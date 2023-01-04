#include <iostream>
#include <algorithm>
#include <queue>
#include <thread>
#include <chrono>
#include <mutex>
#include <future>

struct Solution
{
    int threadCount;
    int printPos;
    int printLimit;
    int allowedThread;

    std::vector<std::thread> threads;
    std::vector<std::thread::id> threadIds;
    std::mutex mtx;
    std::condition_variable cv;

    Solution(int threadCount, int printLimit) : threadCount(threadCount), printLimit(printLimit)
    {
        // threads.resize(threadCount);
        // threadIds.resize(threadCount);
        allowedThread = 0;
        printPos = 1;
    };

    void WaitForAllThreads();

    void Run();

    void Thread_Func();

    void Print();
};

void Solution::Print()
{
    std::cout << printPos << ":"
              << std::this_thread::get_id() << "\n";
}

void Solution::Thread_Func()
{
    while (true)
    {
        WaitForAllThreads();
        std::unique_lock<std::mutex> ul(mtx);
        cv.wait(ul, [this]()
                { return std::this_thread::get_id() == threadIds[allowedThread]; });

        Print();
        if (++printPos > printLimit)
            break;

        allowedThread = (allowedThread + 1) % threadCount;
        ul.unlock();
        cv.notify_all();
    }
}

void Solution::WaitForAllThreads()
{
    while (true)
        if (threadIds.size() == threadCount)
            return;
}

void Solution::Run()
{
    for (int i = 0; i < threadCount; ++i)
    {
        std::thread t(&Solution::Thread_Func, this);

        std::cout << "created a thread " << t.get_id() << "\n";
        threadIds.push_back(t.get_id());
        threads.push_back(std::move(t));
    }

    for (int i = 0; i < threadCount; ++i)
        threads[i].join();
}

int main()
{
    Solution obj(2, 10);

    obj.Run();

    return 0;
}