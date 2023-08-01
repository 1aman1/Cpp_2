#include <iostream>
#include <mutex>
#include <thread>
#include <condition_variable>

class ThreadNNeedle
{
    std::condition_variable cv;
    std::mutex mutex;

    int flag = 1;
    const int RANGE = 10;

public:
    void thread1()
    {
        for (int i = 0; i < RANGE; i += 2)
        {
            std::unique_lock<std::mutex> lock(mutex);
            cv.wait(lock,
                    [this]
                    { return flag & 1 ? 1 : 0; });
            std::cout << "thread 1: " << flag++ << std::endl;
            lock.unlock();
            cv.notify_one();
        }
    }

    void thread2()
    {
        for (int i = 1; i < RANGE; i += 2)
        {
            std::unique_lock<std::mutex> lock(mutex);
            cv.wait(lock,
                    [this]
                    { return flag & 1 ? 0 : 1; });
            std::cout << "thread 2: " << flag++ << std::endl;
            lock.unlock();
            cv.notify_one();
        }
    }
};

int main()
{
    ThreadNNeedle obj;
    std::thread t1(&ThreadNNeedle::thread1, &obj);
    std::thread t2(&ThreadNNeedle::thread2, &obj);

    t1.join();
    t2.join();

    return 0;
}
