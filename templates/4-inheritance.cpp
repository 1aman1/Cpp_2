#include <iostream>

template <class B>
class Base
{
public:
    B p;

private:
};

template <class T>
class Derived : public Base<T>
{
    T q;
};

int main()
{
    Base<short> bobj;

    Derived<int> dobj;

    return 0;
}