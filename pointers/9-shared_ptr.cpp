#include <iostream>
#include <memory>
class Base
{
public:
    Base() { std::cout << "Base::Base()" << std::endl; }

    Base(int x) { std::cout << "Base::Base(1 arg)" << std::endl; }

    void
    func() { std::cout << "Base::func()" << std::endl; }
};

int main()
{
    std::shared_ptr<Base> SPtr(new Base);

    SPtr->func();

    std::cout << "address:" << SPtr.get() << std::endl;

    std::shared_ptr<Base> SPtr2(SPtr); // INSTEAD

    std::shared_ptr<Base> SPtr3 = SPtr;

    // std::cout << "address:" << SPtr.get() << std::endl;
    std::cout << "address:" << SPtr2.get() << std::endl;
    std::cout << "address:" << SPtr3.get() << std::endl;

    std::cout << "reference counts:" << SPtr3.use_count() << std::endl;

    auto SPtr4 = std::make_shared<Base>(1);

    SPtr4->func();

    std::cout << "reference counts:" << SPtr4.use_count() << std::endl;

    return 0;
}