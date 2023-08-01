#include <iostream>

class custom
{
private:
    int data;

public:
    custom(){};
    custom(int x) : data(x){};

    friend void fun(custom &);
};

void fun(custom &obj)
{
    std::cout << "base data " << obj.data << "\n";
    obj.data = 200;
    std::cout << "base data " << obj.data << "\n";
}

int main()
{
    custom obj(10);
    fun(obj);

    return 0;
}