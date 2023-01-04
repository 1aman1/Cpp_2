#include <iostream>
#include <thread>

class sth
{
public:
    sth()
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }

    // first () is syntax, second() is paramter
    void operator()()
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }
};

int main()
{
    // sth o;

    std::thread t((sth()));

    t.join();

    return 0;
}