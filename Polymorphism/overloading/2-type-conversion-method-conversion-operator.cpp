#include <iostream>

struct Base
{
    char character;
    float digit;
    int data;

    Base(int x) : data(x) { std::cout << __PRETTY_FUNCTION__ << std::endl; }
    Base(float x) : digit(x) { std::cout << __PRETTY_FUNCTION__ << std::endl; }

    // conversion operators
    operator int() const
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
        return data;
    }

    operator float() const
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
        return digit;
    }
};

int main()
{
    /**
     * user defined to primitive type
     */

    // for a int
    Base obj(10);

    int idata = obj;
    std::cout << idata << std::endl;

    // again,
    // using static_cast, uses the same conversion operator

    idata = static_cast<int>(obj);
    std::cout << idata << std::endl;

    // NOW,
    // for a float
    obj = float(20.0);

    float fdata = obj;
    std::cout << fdata << std::endl;

    /**
     * primitive type to user defined
     */
    // for a int
    idata = 40;
    obj = idata;
    std::cout << obj.data << std::endl;

    // for a float
    fdata = 50.0;
    obj = fdata;
    std::cout << obj.digit << std::endl;

    return 0;
}