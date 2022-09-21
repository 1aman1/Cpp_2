#include <iostream>

/*
pointer is upgraded, object knowledge remains same
*/

class base
{
public:
    virtual void
    basefun(){};
};

class derived : public base
{
public:
    void
    derfun(){};
};

void checkIsNull(void *Ptr)
{
    if (Ptr == nullptr)
        std::cout << "fail";
    else
        std::cout << "success\n";
}

int main()
{
    // base *Pb = new base(); // FAILS
    base *Pb = new derived();

    derived *Pd = dynamic_cast<derived *>(Pb);

    checkIsNull(Pd);

    Pb->basefun();
    Pd->derfun();

    return 0;
}