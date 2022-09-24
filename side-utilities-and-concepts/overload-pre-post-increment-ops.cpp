#include <iostream>

class wrInt
{
    int data;

public:
    wrInt(int x) : data(x){};

    wrInt() = delete;
    ~wrInt() = default;

    wrInt operator++()
    {
        ++data;
        return *this;
    }

    wrInt operator++(int)
    {
        wrInt tmp = *this;
        ++(*this);
        return tmp;
    }

    int getData() { return data; }
};

int main()
{
    wrInt obj(1);

    std::cout << (obj++).getData();

    std::cout << (++obj).getData();

    return 0;
}