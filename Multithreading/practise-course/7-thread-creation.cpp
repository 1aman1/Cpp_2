#include <iostream>
#include <thread>
#include <chrono>

void func(int &x)
{
    std::cout << x << " : "
              << std::this_thread::get_id()
              << std::endl;

    x = 200;
}

int main()
{
    int localX = 7;

    // variable is explicitly passed as reference in calling function also
    std::thread T(func, std::ref(localX));

    if (T.joinable())
        T.join();

    std::this_thread::sleep_for(std::chrono::milliseconds(200));

    // modified by thread T
    std::cout << localX << std::endl;

    return 0;
}
