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
    virtual ~base()
    {
        std::cout << "~base"
                  << "LINE :" << __LINE__ << std::endl;
    }

    // test by making non virtual/virtual
    // void print()
    virtual void print()
    {
        std::cout << "print base"
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

    void print()
    {
        std::cout << "print derived"
                  << "LINE :" << __LINE__ << std::endl;
    }
};

int main()
{
    std::cout << "LINE :" << __LINE__ << std::endl;
    base *pBase_der = new derived(35);

    std::cout << "LINE :" << __LINE__ << std::endl;
    pBase_der->print();

    std::cout << "LINE :" << __LINE__ << std::endl;
    delete pBase_der;

    // std::cout << "LINE :" << __LINE__ << std::endl;
    // derived *pder_der = new base(35);

    // std::cout << "LINE :" << __LINE__ << std::endl;
    // pder_der->print();

    // std::cout << "LINE :" << __LINE__ << std::endl;
    // delete pder_der;

    return 0;
}