#include <iostream>

/*
on how pointers and an array turn out to be closer than they admit
*/

int main()
{
    int fixedSizeArr[3][3] = {{1, 1, 1}, {2, 2, 2}, {3, 3, 3}};

    int *ptrToArr = fixedSizeArr[0];
    std::cout << ptrToArr << "\n"
              << &fixedSizeArr[0][0] << std::endl;

    ptrToArr++;
    std::cout << ptrToArr << "\n"
              << &fixedSizeArr[0][1] << std::endl;

    ptrToArr++;
    ptrToArr++;
    std::cout << ptrToArr << "\n"
              << &fixedSizeArr[1][0] << std::endl;
              
    return 0;
}