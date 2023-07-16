#include <iostream>
#include <memory>
class Base
{
public:
    Base() { std::cout << "Base::Base()" << std::endl; }

    void show() { std::cout << "Base::show()" << std::endl; }
};

int main()
{
    std::unique_ptr<Base> ptrBase(new Base);

    std::cout << ptrBase.get() << std::endl;
    ptrBase->show();

    // std::auto_ptr<Base> newPtrBase(ptrBase);   DOESN'T SUPPORT MULTIPLE OWNERSHIP
    std::unique_ptr<Base> newPtrBase = std::move(ptrBase);

    ptrBase->show();
    std::cout << ptrBase.get() << std::endl;

    newPtrBase->show();
    std::cout << newPtrBase.get() << std::endl;

    // single ownership method
    // std::unique_ptr<Base> pointer_3 = ptrBase;

    return 0;
}