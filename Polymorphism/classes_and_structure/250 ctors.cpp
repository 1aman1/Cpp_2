#include <iostream>

class base
{
    int data;
public:
    
    base(int x) : data(x)
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }

    base(const base &b)
    {
        this->data = b.data;
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }
};

base func(base b)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    return b;
}

int main()
{
    base obj(1);

    base obj2 = obj;

    base obj3(obj);

    // mischievously similar to line 30
    base tmp = func(obj);

    return 0;
}