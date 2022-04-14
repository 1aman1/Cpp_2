#include <iostream>

/*
    var, pointer and pointer to a pointer
*/

int main()
{
    int var = 101;
    int *ptr = nullptr;

    std::cout << "value stored in var " << var << std::endl;

    std::cout << "Ptr itself " << ptr << std::endl;

    std::cout << "Ptr dereferencing " << *ptr << std::endl;

    ptr = &var;

    std::cout << "Ptr itself " << ptr << std::endl;

    std::cout << "Ptr dereferencing " << *ptr << std::endl;

    return 0;
}