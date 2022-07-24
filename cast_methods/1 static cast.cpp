#include <iostream>
using namespace std;
class Base
{
public:
    Base(){};
    ~Base(){};
    void fun()
    {
        cout << "Base Class fun" << endl;
    }
};
class Derived : public Base
{
public:
    Derived(){};
    ~Derived(){};
    void fun()
    {
        cout << "Child Class fun" << endl;
    }
};
int main()
{
    Derived dObj;
    Base *bObj = &dObj;
    bObj->fun();

    static_cast<Derived *>(bObj)->fun();

    return 0;
}