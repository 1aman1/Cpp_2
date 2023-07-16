#include <iostream>

class Base
{
public:
    virtual ~Base() {}
};

class Derived : public Base
{
public:
    void foo()
    {
        std::cout << "Derived::foo() called." << std::endl;
    }
};

int main()
{
    Base *basePtr = new Derived();

    // Attempt to downcast basePtr to a Derived*.
    Derived *derivedPtr = dynamic_cast<Derived *>(basePtr);

    if (derivedPtr != nullptr)
    {
        std::cout << "Downcast successful. Calling derivedPtr->foo(): ";
        derivedPtr->foo();
    }
    else
    {
        std::cout << "Downcast failed." << std::endl;
    }

    delete basePtr;
    return 0;
}
