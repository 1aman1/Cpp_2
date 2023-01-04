#include <iostream>
#include <algorithm>
#include <vector>
#include <thread>
#include <chrono>
#include <mutex>

void thread_func(const int i)
{
    std::cout << i << " thread with ID : "
              << std::this_thread::get_id()
              << "\n";
}

int main()
{
    std::vector<std::thread> workers;
    for (int i = 0; i < 5; i++)
    {
        workers.push_back(std::thread(thread_func, i));
    }
    std::cout << "main thread\n";

    // Looping every thread via for_each
    // The 3rd argument assigns a task
    // It tells the compiler we're using lambda ([])
    // The lambda function takes its argument as a reference to a thread, t
    // Then, joins one by one, and this works like barrier
    std::for_each(workers.begin(), workers.end(), [](std::thread &t)
                  { t.join(); });

    return 0;
}