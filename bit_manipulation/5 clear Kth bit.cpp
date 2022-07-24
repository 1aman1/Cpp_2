#include <iostream>
#include <bitset>

int method1(int number, int Kth)
{
    return (number & ~(1 << Kth));
}

int main()
{
    int number = 10;
    int Kth = 2;

    std::cout << number << ":" << std::bitset<8>(number) << " " << Kth << std::endl;
    number = method1(number, Kth - 1);
    std::cout << number << ":" << std::bitset<8>(number) << std::endl;

    number = 15;
    Kth = 3;

    std::cout << number << ":" << std::bitset<8>(number) << " " << Kth << std::endl;
    number = method1(number, Kth - 1);
    std::cout << number << ":" << std::bitset<8>(number) << std::endl;

    return 0;
}
