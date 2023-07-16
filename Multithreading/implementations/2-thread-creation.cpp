#include <iostream>
#include <algorithm>
#include <vector>
#include <thread>

int main()
{
    std::thread T([](const int &id)
                  { std::cout << "thread id: " << id << std::endl; },
                  2);

    if (T.joinable())
        T.join();
    else
        std::cout << "not joinable\n";
    return 0;
}