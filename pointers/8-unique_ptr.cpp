#include <iostream>
#include <memory>
class Base
{
public:
    void show() { std::cout << "Base::show()" << std::endl; }
    Base() { std::cout << "Base::Base()" << std::endl; }
};

int main()
{
    std::unique_ptr<Base> pointer_1(new Base);

    pointer_1->show();

    std::cout << pointer_1.get() << std::endl;

    // std::auto_ptr<Base> pointer_2(pointer_1);   INSTEAD
    std::unique_ptr<Base> pointer_2 = std::move(pointer_1);

    // single ownership method
    // std::unique_ptr<Base> pointer_3 = pointer_1;

    std::cout << pointer_1.get() << std::endl;
    std::cout << pointer_2.get() << std::endl;

    return 0;
}