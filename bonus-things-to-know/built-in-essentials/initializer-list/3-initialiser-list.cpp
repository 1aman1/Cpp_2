#include <iostream>
#include <numeric>
#include <vector>

/*
places

Base class object,
derived class construction

 */
class Base
{
    const int data;

public:
    Base();

    Base(int x) : data(x) {}
};

class derived : Base
{
    Base data;

public:
    // FAIL
    // derived(Base tmp) { data = tmp; }

    // PASS
    derived(Base tmp) : data(tmp) {}
};

int main()
{

    Base obj(1);

    return 0;
}