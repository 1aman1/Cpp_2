#include <iostream>

/*
class test{};
*/

// The class after the enum specifies that an enumeration is strongly typed and that its enumerators
// are scoped. Being separate types, enum classes help prevent accidental misuses of constants

// enum class rainbow
enum class rainbow
{
    v = -1,
    i,
    b,
    g = b,
    y,
    o,
    r = i
};

struct mycheck
{
    typedef int type;
};

template <typename T>
struct myunderlyting_type
{
    typedef typename T::type type;
};

class sth
{
public:
    sth &operator,(int a)
    {
        myval += a;
        std::cout << myval << std::endl;
        return *this;
    }

    int myval = 0;
};
int main()
{
    myunderlyting_type<mycheck>::type v;
    v = 10;
    sth s;
    s = s, 1, 2;

    // rainbow color = rainbow::b;
    // std::cout << (int)color << std::endl;

    // std::cout << static_cast<std::underlying_type<rainbow>::type>(color) << std::endl;

    return 0;
}