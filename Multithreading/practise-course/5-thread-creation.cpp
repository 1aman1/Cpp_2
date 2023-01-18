#include <iostream>
#include <algorithm>
#include <vector>
#include <thread>

struct Base
{
    void func(int x)
    {
        std::cout << x << " thread came here\n";
    }
};

int main()
{
    Base obj;
    std::thread T(&Base::func, &obj, 5);

    if (T.joinable())
        T.join();

    return 0;
}