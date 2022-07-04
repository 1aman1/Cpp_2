#include <iostream>

/*
class test{};
*/

class newint
{
    int i;

public:
    newint();
    newint(int x);
    newint operator+(newint y);

    void getVal();
};

newint::newint() : i(0)
{
    std::cout << __PRETTY_FUNCTION__ << " " << this->i << std::endl;
}

newint::newint(int x) : i(x)
{
    std::cout << __PRETTY_FUNCTION__ << " " << this->i << std::endl;
}

newint newint::operator+(newint y)
{
    std::cout << __PRETTY_FUNCTION__ << " " << this->i << std::endl;
    newint tmp;
    tmp.i = this->i + y.i;
    return tmp;
}

void newint::getVal()
{
    std::cout << "value " << i << " " << std::endl
              << std::endl;
}

int main()
{
    newint a(2);
    newint b(3);

    newint c = a + b;
    c.getVal();

    newint d = c;
    d.getVal();

    newint e(d);
    e.getVal();

    return 0;
}