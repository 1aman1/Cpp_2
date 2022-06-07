#include <iostream>

class base
{
private:
    int value;

public:
    base(int x)
    {
        value = x;
    }
    virtual void fun()
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }
};

class derived : public base
{
private:
    int a;

public:
    derived(int x, int y) : base(x)
    {
        base *b;
        b = this;
        b->fun(); // calls derived::fun()
    }

    void fun()
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }
};

int main()
{
    derived obj(1, 2);
    return 0;
}