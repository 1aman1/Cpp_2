#include <iostream>

int main()
{
    int **ptr2ptr = nullptr;

    std::cout << "Ptr2Ptr itself " << ptr2ptr << std::endl;

    std::cout << "Ptr2Ptr dereferencing " << *ptr2ptr << std::endl;

    std::cout << "Ptr2Ptr double dereferencing " << **ptr2ptr << std::endl;

    ptr2ptr = &ptr;

    std::cout << "Ptr2Ptr itself " << ptr2ptr << std::endl;
    std::cout << "Ptr2Ptr dereferencing " << *ptr2ptr << std::endl;

    std::cout << "Ptr2Ptr double dereferencing " << **ptr2ptr << std::endl;

    return 0;
}
