#include <iostream>

/*
how pointers and an array turn out to be closer than they admit
*/

// WIP
int main()
{
    std::cout << "give me size for matrix :";
    int size;
    std::cin >> size;

    // declare a pointer to a pointer when 2d array is needed
    int **ptrToDynamicArr = new int *[size];

    // allocate columnful of memory to each row location pointer
    for (int i = 0; i < size; ++i)
        ptrToDynamicArr[i] = new int[size];

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; ++j)
        {
            ptrToDynamicArr[i][j] = i + j; // << " " << std::endl;
        }
    }

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; ++j)
        {
            std::cout << ptrToDynamicArr[i][j] << " " << std::endl;
        }
    }

    delete[] ptrToDynamicArr;

    return 0;
}