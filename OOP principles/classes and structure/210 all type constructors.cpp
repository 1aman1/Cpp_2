#include <iostream>

class test
{
    int var;

public:
    test()
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }

    test(int x)
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;

        this->var = x;
    }

    test(const test &tmpTestObj)
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;

        this->var = tmpTestObj.var;
    }

    void printVar()
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;

        std::cout << var << std::endl;
    }
    void printVarTwo(test tmp)
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;

        std::cout << var << std::endl;
    }
};
test fun()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;

    test t;
    return t;
}

int main()
{
    /*
    test t1;
    t1.printVar();

    test t2(20);
    t2.printVar();

    test t3 = t2;
    t3.printVar();

    test t4;
    t4 = t3;
    t4.printVar();
    */

    /* test t1(100);
     t1.printVarTwo(t1);
 */

    test t1;
    test t2 = fun();

    return 0;
}