
#include <iostream>

int add(int lhs, int rhs)
{
    return lhs + rhs;
}

int fun(int (*funcP)(int, int))
{
    return funcP(2, 3);
}

int main()
{
    std::cout << fun(add);

    return 0;
}