#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include <condition_variable>

/*
> the CV allows running threads to wait on some conditions and once the condition is satisfied the waiting thread can be notified to awaken by the help of notify_one / notify_all
> a mutex is needed to use CV mechanism
> Three things happen if a thread wants to wait on some condition
>> acquire lock using mechanism like unique lock
>> use wait/ wait for / wait until, this wait operation atomically releases the mutex and suspends the thread
>> when the CV is notified, the thread awakens and reacquires the mutex lock, after that it rechecks the condition to verify if this was a spuriouos call to CV.
*/

std::condition_variable cv;
std::mutex mtx;
int balance = 0;

void Add_Money(int amount)
{
    std::lock_guard<std::mutex> lg(mtx);
    balance += amount;
    std::cout << amount << " credited\n";
    cv.notify_one();
    // cv.notify_all();
}

void Withdraw_Money(int amount)
{
    std::unique_lock<std::mutex> ul(mtx);
    cv.wait(ul, []()
            { return balance == 0 ? false : true; });
    if (balance >= amount)
    {

        balance -= amount;
        std::cout << amount << " deducted\n";
    }
    else
    {
        std::cout << amount << " not deducted_INSUFFICIENT BALANCE\n";
    }
}

int main()
{
    std::thread t2(Withdraw_Money, 500);
    // std::this_thread::sleep_for(std::chrono::seconds(2));
    std::thread t1(Add_Money, 5000);

    std::cout << "pre main thread \n";

    if (t1.joinable())
        t1.join();
    if (t2.joinable())
        t2.join();

    std::cout << "post main thread\n";
    std::cout << balance << " wallet\n";

    return 0;
}
