#include <iostream>

/*
pointer is upgraded, object knowledge remains same
*/

class base
{
public:
    virtual void
    Existing_Functions(){};
};

class derived : public base
{
public:
    void
    New_Functions(){};
};

void If_Cast_Successful(void *Ptr)
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

    If_Cast_Successful(ptrToDerived);

    ptrToBase->Existing_Functions();

    // ptrToBase->New_Functions(); // This we can't do

    // But after dynamic cast to a new derived class pointer we can do that
    ptrToDerived->New_Functions();

    return 0;
}