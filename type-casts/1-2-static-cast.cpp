#include <iostream>
using namespace std;

class Base
{
public:
    void fun() { cout << "Base Class fun" << endl; }
};

class Derived : public Base
{
public:
    void fun() { cout << "Child Class fun" << endl; }
};

int main()
{
    Derived derivedInstance;
    Base *baseInstance = &derivedInstance;
    baseInstance->fun();

    static_cast<Derived *>(baseInstance)->fun();

    return 0;
}