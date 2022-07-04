#include <iostream>

class Base
{
    int x;
    int y;

public:
    Base(int a = 0, int b = 0)
    {
        x = a;
        y = b;
    }

    ~Base() {}

    // Base c = a + b;
    // here the call's context is of 'a' obj, and 'b' is passed as parameter
    //
    Base operator+(const Base &c)
    {
        return Base(this->x + c.x, this->y + c.y);
    }

    void get()
    {
        std::cout << "x " << x << "\ny " << y << std::endl;
    }
};

int main()
{
    Base a(1, 2);
    Base b(2, 1);
    Base c = a + b;
    c.get();

    // Base d;
    // d.get();

    return 0;
}