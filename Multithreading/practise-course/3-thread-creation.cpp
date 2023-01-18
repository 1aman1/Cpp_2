#include <iostream>
#include <algorithm>
#include <vector>
#include <thread>

struct Base
{
    static void func(int x)
    {
        std::cout << x << " thread came here\n";
    }
};

int main()
{
    Base obj;

    std::thread T(obj.func, 3); // passing parameter 2

    T.join();

    return 0;
}