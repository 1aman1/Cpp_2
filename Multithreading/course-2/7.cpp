#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <map>
#include <bitset>
#include <list>
#include <thread>
#include <chrono>

class Solution
{
public:
    void tfun(int x)
    {
        std::cout << x << " thread was here\n";
        std::this_thread::sleep_for(std::chrono::seconds(2));
        return;
    }
};

int main()
{
    Solution obj;
    std::thread t1(&Solution::tfun, &obj, 7);
    std::cout << "pre main thread \n";

    // t1.detach();
    if (t1.joinable())
        t1.join();

    std::cout << "post main thread\n";
    return 0;
}
