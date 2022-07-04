#include <iostream>

class base
{
public:
    int b1 = 1;
    base()
    {
        std::cout << "base(def)"
                  << "LINE :" << __LINE__ << std::endl;
    }
    base(int i)
    {
        std::cout << "base(custom)" << i << "LINE :" << __LINE__ << std::endl;
    }
    ~base()
    {
        std::cout << "~base"
                  << "LINE :" << __LINE__ << std::endl;
    }
};

class derived : public base
{
public:
    int d2 = 2;
    derived(int i)
    {
        std::cout << "derived " << i << "LINE :" << __LINE__ << std::endl;
    }
    ~derived()
    {
        std::cout << "~derived"
                  << "LINE :" << __LINE__ << std::endl;
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