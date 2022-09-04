#include <iostream>

class Base
{
public:
private:
};

template <class T>
class Derived : public Base
{
    T q;
};

int main()
{
    Base bobj;

    Derived<int> dobj;

    return 0;
}