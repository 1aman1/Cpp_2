
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
    // both 1 & 2 function pointer declarations are valid
    // #1
    // int (*funP)(short, double) = &fun;

    // #2
    int (*funP)(short, double) = fun;

    // both 1 & 2 function pointer usages are valid
    // #1
    std::cout << (*funP)(2, 3.4) << "\n";

    // #2
    std::cout << funP(1, 2.5) << "\n";

    // #2 being the preferred one in both the scenarios above.

    return 0;
}