#include <iostream>
#include <bitset>

bool method1(int number, int Kth)
{
    return (number >> Kth) & 1;
}

bool method2(int number, int Kth)
{
    return (number & (1 << Kth));
}

int main()
{
    int number = 10;
    int Kth = 2;

    std::cout << std::bitset<8>(number) << " " << Kth << std::endl;

    method1(number, Kth - 1) ? std::cout << "Yes\n" : std::cout << "No\n";
    method2(number, Kth - 1) ? std::cout << "Yes\n" : std::cout << "No\n";

    number = 16;
    Kth = 2;

    std::cout << std::bitset<8>(number) << " " << Kth << std::endl;

    method1(number, Kth - 1) ? std::cout << "Yes\n" : std::cout << "No\n";
    method2(number, Kth - 1) ? std::cout << "Yes\n" : std::cout << "No\n";

    return 0;
}
