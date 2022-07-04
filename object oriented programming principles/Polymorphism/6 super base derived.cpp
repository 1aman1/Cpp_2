#include <iostream>
using namespace std;
class ISuperbase
{
public:
    virtual void print() = 0;
    virtual void display() = 0;
};
class Base : public ISuperbase
{
public:
    virtual void print()
    {
        cout << "print function of middle class" << endl;
    }
};
class Derived : public Base
{
    virtual void display()
    {
        cout << "In display function" << endl;
    }
};
int main(void)
{
    // base remains abstract by not defining PV function
    // Base b;
    // derive class object
    Derived d;
    // virtual function, binded at runtime
    d.print();
    return 0;
}