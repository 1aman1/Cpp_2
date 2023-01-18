#include <iostream>
#include <mutex>
#include <thread>
#include <condition_variable>
#include <vector>

constexpr int RANGE = 12;

std::mutex mu;
std::condition_variable cv_1, cv_2, cv_3;

int i = 0;

// void f1(int id)
// {
//     while (i < RANGE)
//     {
//         std::unique_lock<std::mutex> lock(mu);

//         cv_arr[(id - 1) % 3].wait(lock);

//         if (i < RANGE)
//         {
//             ++i;
//             std::cout  << std::endl;
//             std::cout << std::this_thread::get_id() << " " << i << std::endl;
//         }

//         lock.unlock();

//         cv_arr[(id) % 3].notify_one();
//     }
// }

void f1()
{
    while (i < RANGE)
    {
        std::unique_lock<std::mutex> lock(mu);
        cv_1.wait(lock);
        if (i < RANGE)
        {
            ++i;
            std::cout << i << std::endl;
        }
        std::cout << " f1 \n"
                  << std::endl;
        lock.unlock();
        cv_2.notify_one();
    }
}

void f2()
{
    while (i < RANGE)
    {
        std::unique_lock<std::mutex> lock(mu);
        cv_2.wait(lock);
        if (i < RANGE)
        {
            ++i;
            std::cout << i << std::endl;
        }
        std::cout << " f2 \n"
                  << std::endl;

        lock.unlock();
        cv_3.notify_one();
    }
}

void f3()
{
    while (i < RANGE)
    {
        std::unique_lock<std::mutex> lock(mu);
        cv_3.wait(lock);
        if (i < RANGE)
        {
            ++i;
            std::cout << i << std::endl;
        }
        std::cout << " f3 \n"
                  << std::endl;

        lock.unlock();
        cv_1.notify_one();
    }
}

int main()
{
    std::thread t1(f1);
    std::thread t2(f2);
    std::thread t3(f3);

    cv_1.notify_one();

    t1.join();
    t2.join();
    t3.join();

    return 0;
}