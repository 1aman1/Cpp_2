#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <map>
#include <bitset>
#include <list>
#include <thread>

class Solution
{
public:
};

int main()
{
    std::thread t1([](const int x)
                   { std::cout << x << " thread was here\n"; },
                   2);
    t1.join();

    return 0;
}