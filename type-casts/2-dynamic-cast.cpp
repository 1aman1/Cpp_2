#include <iostream>

/*
pointer is upgraded, object knowledge remains same
*/

class base
{
public:
    virtual void existingFunctions(){};
};

class derived : public base
{
public:
    void newFunctions(){};
};

void ifCastSuccessful(void *Ptr)
{
    if (Ptr == nullptr)
        std::cout << "fail";
    else
        std::cout << "success\n";
}

int main()
{
    base *ptrToBase = new derived();

    // when we need pointer to derived class, where new functionality maybe present
    derived *ptrToDerived = dynamic_cast<derived *>(ptrToBase);

    ifCastSuccessful(ptrToDerived);

    ptrToBase->existingFunctions();

    // ptrToBase->newFunctions(); // This we can't do

    // But after dynamic cast to a new derived class pointer we can do that
    ptrToDerived->newFunctions();

    return 0;
}