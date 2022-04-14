#include <iostream>

/*
on how pointers and an array turn out to be closer than they admit
*/

int main()
{
    int fixedSizeArr[4] = {101, 202, 303, 404};

    int *ptrToArr = fixedSizeArr;

    std::cout << ptrToArr << "\n"
              << &fixedSizeArr[0] << std::endl;

    ptrToArr++;
    std::cout << ptrToArr << "\n"
              << &fixedSizeArr[1] << std::endl;

    // dynamically create an array
    int size;
    std::cin >> size;
    int *ptrToDynamicArr = new int[size];

    for (int i = 0; i < size; ++i)
        ptrToDynamicArr[i] = 1;

    for (int i = 0; i < size; ++i)
        std::cout << ptrToDynamicArr[i] << " ";

    return 0;
}