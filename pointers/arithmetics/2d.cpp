#include <iostream>

int main()
{
    int B[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    std::cout << B;
    std::cout << std::endl;
    std::cout << *B;
    std::cout << std::endl;
    std::cout << B[0];
    std::cout << std::endl;
    std::cout << &B[0];
    std::cout << std::endl;

    std::cout << *(B[0]);
    std::cout << std::endl;
    
    return 0;
}