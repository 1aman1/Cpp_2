#include <iostream>
#include <thread>

void func(int x)
{
    std::cout << x << " : "
              << std::this_thread::get_id()
              << std::endl;
}

int main()
{
    std::thread T(func, 12);

    if (T.joinable())
        T.join();

    // std::thread T2 = T;
    std::thread T2 = move(T);

    if (T2.joinable())
        T2.join();

    return 0;
}