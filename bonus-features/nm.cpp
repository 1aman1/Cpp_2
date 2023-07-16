#include <iostream>

class Base
{
    int data;

public:
    Base(int x) : data(x) {}

    Base(const Base &rhs)
    {
        this->data = rhs.data;
    }
};

void func(Base tmp)
{
}

int main()
{

    return 0;
}