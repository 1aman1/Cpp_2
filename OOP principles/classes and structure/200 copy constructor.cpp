#include <iostream>

class Base
{
    int x;
    int y;

public:
    ~Base() {}

    Base(int a = 0, int b = 0)
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
        this->x = a;
        this->y = b;
    }

    Base(const Base &tmp)
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
        this->x = tmp.x;
        this->y = tmp.y;
    }

    void get()
    {
        std::cout << "x " << x << "\ny " << y << std::endl;
    }
};

int main()
{

    Base a(1, 2);

    // copy constructor
    Base c = a;
    c.get();

    return 0;
}