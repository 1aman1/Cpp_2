#include <iostream>
#include <vector>

void func(int *Plen)
{
    std::cout << Plen << " " << *Plen << "\n";
}

int main()
{

    const int len = 3;

    const int *Plen = &len;

    func(const_cast<int *>(Plen));

    return 0;
}