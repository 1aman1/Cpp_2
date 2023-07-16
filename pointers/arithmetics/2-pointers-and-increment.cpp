#include <iostream>

/*
on how pointers and an array turn out to be closer than they admit
*/

int main()
{
    int fixedSizeArr[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    int *ptrToArr = fixedSizeArr[0];
    std::cout << ptrToArr << " : " << *ptrToArr << "\n"
              << &fixedSizeArr[0][0] << " : " << fixedSizeArr[0][0] << std::endl;

    ptrToArr++;
    std::cout << ptrToArr << " : " << *ptrToArr << "\n"
              << &fixedSizeArr[0][1] << " : " << fixedSizeArr[0][1] << std::endl;

    ptrToArr++;
    ptrToArr++;
    std::cout << ptrToArr << " : " << *ptrToArr << "\n"
              << &fixedSizeArr[1][0] << " : " << fixedSizeArr[1][0] << std::endl;

    return 0;
}