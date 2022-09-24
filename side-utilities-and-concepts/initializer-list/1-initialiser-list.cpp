#include <iostream>
#include <numeric>
#include <vector>

/* 
places

we can't initialize not-static const data member without IList.
const int data;

 */
class Base
{
    const int data;

public:
    Base();

    // FAIL
    // Base(int x)
    // {
    //     data = x;
    // }

    // PASS
    Base(int x) : data(x) {}

    int getData() { return data; }
};

int main()
{

    Base obj(1);

    std::cout << obj.getData() << "\n";

    return 0;
}