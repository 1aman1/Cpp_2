#include <iostream>
#include <typeinfo>

class Base
{
private:
    int data;

public:
    Base(){};
};

int main()
{
    auto i_v = 5;
    auto f_v = 15.9;
    auto o_base = Base();
    auto p_base = new Base();

    std::cout << typeid(i_v).name() << std::endl;
    std::cout << typeid(f_v).name() << std::endl;
    std::cout << typeid(o_base).name() << std::endl;
    std::cout << typeid(p_base).name() << std::endl;

    delete p_base;

    return 0;
}