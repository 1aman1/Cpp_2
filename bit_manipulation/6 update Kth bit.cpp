#include <iostream>
#include <bitset>

int method1(int number, int Kth, int setto)
{
    int mask = ~(1 << Kth);
    return ((number & mask) | (setto << Kth));
}

int main()
{
    int number = 3;
    int Kth = 4;
    int setto = 1;

    std::cout << number << ":" << std::bitset<8>(number) << " " << Kth << std::endl;
    number = method1(number, Kth - 1, setto);
    std::cout << number << ":" << std::bitset<8>(number) << std::endl;

    number = 15;
    Kth = 3;
    setto = 0;

    std::cout << number << ":" << std::bitset<8>(number) << " " << Kth << std::endl;
    number = method1(number, Kth - 1, setto);
    std::cout << number << ":" << std::bitset<8>(number) << std::endl;

    return 0;
}
