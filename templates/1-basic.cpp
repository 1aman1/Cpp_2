#include <iostream>

template <class T>
T add(T a, T b)
{
    std::cout << "Template\n";
    return a + b;
}

int add(int a, int b)
{
    std::cout << "diff func Int\n";

    return a + b;
}

int main()
{
    add<short>(1, 2);
    add(1, 2);

    return 0;
}