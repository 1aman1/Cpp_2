#include <iostream>

class Base
{
    int state;

public:
    Base(int x) : state(x){};

    int operator()(int param)
    {
        return param / state;
    }
};

int main()
{
    Base inst(2);

    std::cout << inst(4);
    std::cout << "\n";
    std::cout << inst(100);
    std::cout << "\n";

    return 0;
}