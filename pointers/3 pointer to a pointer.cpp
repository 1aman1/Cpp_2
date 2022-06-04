#include <iostream>

/*
    var, pointer and pointer to a pointer
  */

int main()
{
    // courses 1
    int var = 101;
    int *ptr = nullptr;

    std::cout << "value stored in var " << var << std::endl;

    std::cout << "Ptr itself " << ptr << std::endl;

    std::cout << "Ptr dereferencing " << *ptr << std::endl;

    ptr = &var;

    std::cout << "Ptr itself " << ptr << std::endl;

    std::cout << "Ptr dereferencing " << *ptr << std::endl;

    // course 2
    int **ptr2ptr = nullptr;

    // this componenet will have different results when compiled with different kind of compilers.

    // de-reference when points to nothing
    std::cout << "Ptr2Ptr itself " << ptr2ptr << std::endl;

    std::cout << "Ptr2Ptr dereferencing " << *ptr2ptr << std::endl;

    std::cout << "Ptr2Ptr double dereferencing " << **ptr2ptr << std::endl;

    ptr2ptr = &ptr;

    std::cout << "Ptr2Ptr itself " << ptr2ptr << std::endl;

    std::cout << "Ptr2Ptr dereferencing " << *ptr2ptr << std::endl;

    std::cout << "Ptr2Ptr double dereferencing " << **ptr2ptr << std::endl;

    return 0;
}