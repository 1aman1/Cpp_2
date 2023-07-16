#include <iostream>

// overloading operator <<

class Base
{
private:
    int data;

public:
    Base(){};
    Base(int x) : data(x){};

    friend void
    fun(Base &);

    friend void
    operator<<(std::ostream &,
               Base &);
};

void operator<<(std::ostream &output, Base &cr_obj)
{
    output << cr_obj.data;
}

int main()
{
    Base obj(10);

    std::cout << obj;

    return 0;
}