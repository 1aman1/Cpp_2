#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include <condition_variable>

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

void Withdraw_Money(int debitAmount)
{
    std::unique_lock<std::mutex> ul(mtx);

    cv.wait(ul, []()
            { return balance > 0 ? true : false; });

    if (debitAmount <= balance)
    {
        balance -= debitAmount;
        std::cout << debitAmount << " deducted\n";
    }
    else
        std::cout << " insufficient balance\n";
}

int main()
{
    std::cout << balance << " wallet\n";
    std::thread t2(Withdraw_Money, 500);

    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::thread t1(Add_Money, 5000);

    if (t1.joinable())
        t1.join();
    if (t2.joinable())
        t2.join();

    std::cout << balance << " wallet\n";

    return 0;
}
