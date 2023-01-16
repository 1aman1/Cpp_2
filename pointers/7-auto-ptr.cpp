#include <iostream>
#include <memory>

/*
WHY THESE ARE DEPRECATED

Containers hold objects, but not the ones you give them. Furthermore, when you get an object from a container, the object you get is not the one that was in the container. Instead, when you add an object to a container (via. e.g., insert or push_back, etc.), what goes into the container is a copy of the object you specify. When you get an object from a container (via. e.g., front or back), what you get is a copy of what was contained. Copy in, copy out. That's the STL way.

- Effective STL by Scott Meyers
*/

class Base
{
public:
    void show() { std::cout << "Base::show()" << std::endl; }

    Base() { std::cout << "Base::Base()" << std::endl; }
};

int main()
{
    std::auto_ptr<Base> pointer_1(new Base);

    pointer_1->show();

    std::cout << pointer_1.get() << std::endl;

    std::auto_ptr<Base> pointer_2(pointer_1);

    std::cout << pointer_1.get() << std::endl;
    std::cout << pointer_2.get() << std::endl;

    return 0;
}