#include <iostream>

// one function for lvalue
void printReference(int &x)
{
    std::cout << "lvalue :" << x << std::endl;
}

// one for rvalue
void printReference(int &&x)
{
    std::cout << "rvalue :" << x << std::endl;
}

int getValue()
{
    // int temp_i = 99;
    return 99;
}

int main()
{
    int x = 11;

    printReference(x);
    printReference(getValue());

    return 0;
}