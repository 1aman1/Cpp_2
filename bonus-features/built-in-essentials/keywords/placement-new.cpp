#include <iostream>

// get a whole chunnk of memory and coonstruct object and destruct on sole responsibility

class Base
{
    int data;

public:
    Base() = default;
    Base(int x) : data(x){};

    ~Base() = default;
};

int main()
{
    Base *regularPointer = new Base();
    delete regularPointer;

    char *memoryLane = new char[sizeof(Base) * 10];

    Base *obj1 = new (&memoryLane[0]) Base(10);
    //
    //
    Base *obj4 = new (&memoryLane[3]) Base(40);
    //
    //
    //
    //
    Base *obj9 = new (&memoryLane[8]) Base(90);

    obj1->~Base();
    //
    obj4->~Base();
    //
    obj9->~Base();


    delete[] memoryLane;

    return 0;
}