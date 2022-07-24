#include <iostream>

class base
{
    int b1 = 1;

public:
    base()
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }

    base(int i)
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }

    ~base()
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }
};

class derived : public base
{
    int d2 = 2;

public:
    derived(int i)
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }

    ~derived()
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }
};

int main()
{

    std::cout << "LINE :" << __LINE__ << std::endl;
    base *pBase_base = new base(30);

    std::cout << "LINE :" << __LINE__ << std::endl;
    delete pBase_base;

    std::cout << "LINE :" << __LINE__ << std::endl;
    base *pBase_der = new derived(35);

    std::cout << "LINE :" << __LINE__ << std::endl;
    delete pBase_der;

    return 0;
}