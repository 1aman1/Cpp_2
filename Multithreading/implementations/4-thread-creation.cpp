#include <iostream>
#include <algorithm>
#include <vector>
#include <thread>

struct Base
{
    static void tfun(int x)
    {
        std::cout << x << " thread came here\n";
    }
};

int main()
{
    std::thread T(&Base::tfun, 4);

    T.join();

    return 0;
}