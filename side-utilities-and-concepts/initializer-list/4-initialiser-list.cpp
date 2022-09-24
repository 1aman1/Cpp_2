#include <iostream>
#include <numeric>
#include <vector>

/*
places

base class members have to be initialsed via call from INITLIST,
they would be inaccessible from the derived CTOR's body.
*/

class Base
{
    int p;

public:
    Base() = default;

    Base(int x) : p(x) {}
};

class Derived : public Base
{
    int q;

public:
    Derived() = default;

    // FAIL
    // Derived(int x, int y)
    // {
    //     p = x;
    //     q = y;
    // };

    // PASS
    Derived(int x, int y) : Base(x), q(y){};
};

int main()
{
    Derived obj(1, 2);

    return 0;
}