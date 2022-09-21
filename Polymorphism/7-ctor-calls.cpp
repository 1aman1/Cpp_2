#include <iostream>

class Base
{
public:
    Base() { std::cout << "\nbase CTOR"; }

    //  void - for RTTI
    void virtual fun()
    {
        std::cout << "\nbase Fun";
    }
};

class Derived : public Base
{
public:
    Derived() { std::cout << "\nderived CTOR"; }

    void fun() { std::cout << "\nderived Fun"; }
};

int main()
{

    Base bObj;
    bObj.fun();

    std::cout << std::endl;
    Derived dObj;
    dObj.fun();

    //------

    std::cout << std::endl;
    Base *Pb2b = new Base();
    Pb2b->fun();

    std::cout << std::endl;
    Base *Pb2d = new Derived();
    Pb2d->fun();

    std::cout << std::endl;
    return 0;
}