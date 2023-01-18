#include <iostream>
#include <algorithm>
#include <vector>
#include <thread>

int main()
{
    std::thread T([](const int x)
                  { std::cout << x << " thread came here\n"; },
                  2);

    T.join();

    return 0;
}