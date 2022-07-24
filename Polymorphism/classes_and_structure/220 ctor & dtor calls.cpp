#include <iostream>

class base
{
    int b1;

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
    int d2;

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
    base bobj;

    std::cout << "LINE :" << __LINE__ << std::endl;
    base bobj2(10);

    std::cout << "LINE :" << __LINE__ << std::endl;
    derived dobj(20);

    std::cout << "LINE :" << __LINE__ << std::endl;
    base *pBase = new base(30);

    std::cout << "LINE :" << __LINE__ << std::endl;
    derived *pDerived = new derived(40);

    std::cout << "LINE :" << __LINE__ << std::endl;

    delete pDerived;
    delete pBase;

    return 0;
}