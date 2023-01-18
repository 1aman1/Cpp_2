#include <iostream>
#include <thread>
#include <mutex>
/*
a std::cout resource fight goes here, on each executio the output comesout different.
*/

std::mutex mu;

void shared_cout(std::string s, int i)
{
    std::lock_guard<std::mutex> guard(mu);
    std::cout << s << " : " << i << std::endl;
}

void thread_function()
{
    for (int i = -10; i < 0; i++)
        shared_cout("thread function", i);
}

int main()
{
    std::thread t(thread_function);

    for (int i = 10; i > 0; i--)
        shared_cout("main function", i);

    t.join();

    std::cout << "main thread \n";

    return 0;
}