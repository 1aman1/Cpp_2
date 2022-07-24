#include <iostream>
#include <bitset>

int main()
{
    int a = 25;

    std::cout << a << " =a," << std::bitset<8>(a) << std::endl;
    a = a >> 1;
    std::cout << a << " =a," << std::bitset<8>(a) << std::endl;
    
    // std::cout << x;

    return 0;
}