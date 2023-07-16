#include <iostream>
#include <memory>
class Base
{
public:
    Base() { std::cout << "Base::Base()" << std::endl; }

    Base(int x) { std::cout << "Base::Base(1 arg)" << std::endl; }

    void myMethod() { std::cout << "Base::myMethod()" << std::endl; }
};

int main()
{
    std::shared_ptr<Base> basePtr(new Base());

    basePtr->myMethod();

    std::cout << "address:" << basePtr.get() << std::endl;

    std::shared_ptr<Base> basePtr2(basePtr); // INSTEAD
    std::shared_ptr<Base> basePtr3 = basePtr;

    std::cout << "address:" << basePtr.get() << std::endl;
    std::cout << "address:" << basePtr2.get() << std::endl;
    std::cout << "address:" << basePtr3.get() << std::endl;

    std::cout << "reference counts:" << basePtr3.use_count() << std::endl;

    auto basePtr4 = std::make_shared<Base>(1);

    basePtr4->myMethod();

    std::cout << "reference counts:" << basePtr4.use_count() << std::endl;

    return 0;
}