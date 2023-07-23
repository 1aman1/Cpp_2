#include <iostream>
#include <typeinfo>

class Base
{
public:
    virtual ~Base() {}
};

class Derived : public Base
{
};

int main()
{
    Base *basePtr = new Derived();

    // Using typeid on a polymorphic object
    const std::type_info &type = typeid(*basePtr);
    std::cout << "Object type: " << type.name() << std::endl;

    // Comparing types
    if (type == typeid(Derived))
    {
        std::cout << "The object is of type Derived." << std::endl;
    }
    else if (type == typeid(Base))
    {
        std::cout << "The object is of type Base." << std::endl;
    }

    delete basePtr;
    return 0;
}
