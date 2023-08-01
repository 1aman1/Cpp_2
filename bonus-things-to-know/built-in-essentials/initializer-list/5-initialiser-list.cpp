#include <iostream>
#include <numeric>
#include <vector>

/*
places

same name as data member
*/

class Base
{
    int p;

public:
    Base() = default;

    // PASS
    Base(int p) : p(p) {}

    // FAIL
    // Base(int p) { p = p; }

    int getData() { return p; }
};

int main()
{
    Base obj(99);

    std::cout << obj.getData();

    return 0;
}