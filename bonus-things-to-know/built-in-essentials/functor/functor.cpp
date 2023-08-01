#include <iostream>

// functors are 'object + ()'

class functor
{
public:
    functor()
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }

    int operator()(int x)
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;

        return (x > 0
                    ? x
                    : -x);
    }
};

int main()
{
    int x = -4;
    std::cout << x << std::endl;

    x = functor()(x);
    std::cout << x << std::endl;

    return 0;
}