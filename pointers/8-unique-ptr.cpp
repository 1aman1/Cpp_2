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
    std::unique_ptr<Base> unPtrBase(new Base);

    unPtrBase->show();

    std::cout << unPtrBase.get() << std::endl;

    // std::auto_ptr<Base> newUnPtrBase(unPtrBase);   INSTEAD
    std::unique_ptr<Base> newUnPtrBase = std::move(unPtrBase);

    // single ownership method
    // std::unique_ptr<Base> pointer_3 = unPtrBase;

    std::cout << unPtrBase.get() << std::endl;
    std::cout << newUnPtrBase.get() << std::endl;

    return 0;
}