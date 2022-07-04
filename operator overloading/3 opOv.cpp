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

    newint operator++();
    newint operator++(int);

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

newint newint::operator++()
{
    std::cout << __PRETTY_FUNCTION__ << " " << this->i << std::endl;

    return newint(++this->i);
}

newint newint::operator++(int tmp)
{
    std::cout << __PRETTY_FUNCTION__ << " " << this->i << std::endl;

    return newint(this->i++);
}

int main()
{
    newint a(2);

    ++a;

    a++;

    a.getVal();

    return 0;
}