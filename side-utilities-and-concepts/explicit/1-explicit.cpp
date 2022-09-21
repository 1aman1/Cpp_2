#include <iostream>

class Base
{
    int data;

public:
    Base() = delete;

    explicit
    Base(int x) : data(x) { std::cout << "1-arg ctor-" << data << "\n"; }

    Base(const Base &rhs)
    {
        this->data = rhs.data;
        std::cout << "copy ctor-" << this->data << "\n";
    }
};

void func(Base tmp)
{
    ;
}

int main()
{
    Base obj_1(10);
    Base obj_2 = obj_1;

    func(Base(30));

    // func(40); // no implicit conversion take place for 'explicit' ctors

    return 0;
}