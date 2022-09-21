
#include <iostream>

/*
while creating function pointers, keep parameter list correct.
The code compiles even if unequal count of parameters are given while creating function pointer
 */
int fun(short c, double t)
{
    return 1;
}

int main()
{
    // BOTH ARE VALID
    int (*funP)(short, double) = fun;
    // int (*funP)(short, double) = &fun;

    // BOTH ARE VALID
    std::cout << funP(1, 2.5) << "\n";

    int data = (*funP)(2, 3.4);

    std::cout << data << "\n";

    return 0;
}