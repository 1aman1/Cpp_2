#include <iostream>

class Base
{
private:
    int data;

public:
    Base(){};
    Base(int x) : data(x){};

    friend void
    fun(Base &);
};

void fun(Base &r_obj)
{
    std::cout << "base data" << r_obj.data << "\n";
}

int main()
{
    Base obj(10);

    fun(obj);

    return 0;
}