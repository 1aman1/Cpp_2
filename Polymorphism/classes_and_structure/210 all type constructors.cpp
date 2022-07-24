#include <iostream>

class base
{
    int var;

public:
    base()
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }

    base(int x)
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;

        this->var = x;
    }

    base(const base &tmpTestObj)
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;

        this->var = tmpTestObj.var;
    }

    void printVar()
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;

        std::cout << var << std::endl;
    }
    
    void printVarTwo(base tmp)
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;

        std::cout << var << std::endl;
    }
};
base fun()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;

    base t;
    return t;
}

int main()
{
    /*
    base t1;
    t1.printVar();

    base t2(20);
    t2.printVar();

    base t3 = t2;
    t3.printVar();

    base t4;
    t4 = t3;
    t4.printVar();
    */

    /* base t1(100);
     t1.printVarTwo(t1);
 */

    base t1;
    base t2 = fun();

    return 0;
}