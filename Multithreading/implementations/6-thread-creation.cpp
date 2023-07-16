#include <iostream>
#include <algorithm>
#include <vector>
#include <thread>

struct Base
{
public:
    void operator()(int x)
    {
        std::cout << x << " thread came here\n";
        return;
    }
};

int main()
{
    std::thread T((Base()), 6); // callable object
    T.join();

    return 0;
}