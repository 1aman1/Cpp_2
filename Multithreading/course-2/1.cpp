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
    static void tfun(int x)
    {
        std::cout << x << " thread was here\n";
        return;
    }
};

int main()
{
    Solution obj;

    std::thread t1(obj.tfun, 1);
    t1.join();

    return 0;
}