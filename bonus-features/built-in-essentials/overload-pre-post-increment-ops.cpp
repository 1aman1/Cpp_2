#include <iostream>

class myInt
{
    int data;

public:
    myInt() = delete;

    myInt(int x) : data(x){};

    ~myInt() = default;

    myInt operator++()
    {
        ++data;
        return *this;
    }

    myInt operator++(int)
    {
        myInt tmp = *this;
        ++(*this);
        return tmp;
    }

    int getInt() { return data; }
};

int main()
{
    myInt obj(1);

    std::cout << (++obj).getInt() << std::endl;
    std::cout << obj.getInt() << std::endl;

    std::cout << (obj++).getInt() << std::endl;
    std::cout << obj.getInt() << std::endl;

    return 0;
}