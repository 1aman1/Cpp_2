#include <iostream>

class base
{
    int data;
    int arr[10];

public:
    base() : data(0)
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }

    base(const int &x) : data(x)
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }

    // copy constructor
    base(const base &tmp)
    {
        this->data = tmp.data;
    }

    // INCREMENT OPERATORS

    // pre-increment
    base operator++()
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;

        ++(this->data);

        // return base(++(this->data)); OR without a new object
        return *this;
    }

    // post-increment
    // keeping int is way of compiler to distinguish pre/post increment
    // it is always int regardless of where you use it
    base operator++(int)
    {
        return base((this->data)++); // nameless temporary object for shortlived objects
    }

    // UNARY OPERATORS

    // ARITHMETIC
    // +
    base operator+(const base &tmp) const
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;

        return base(this->data + tmp.data); // nameless object
    }

    // -
    base operator-(const base &tmp) const
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;

        return base(this->data - tmp.data); // nameless object
    }

    // RELATIONAL
    // > < ==
    bool operator>(const base &tmp) const
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;

        return (this->data > tmp.data)
                   ? true
                   : false;
    }

    bool operator<(const base &tmp) const
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;

        return (!(this->data > tmp.data));
    }

    bool operator==(const base &tmp) const
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;

        return !((this->data > tmp.data) && (this->data < tmp.data));
    }

    // subscript operator
    int &operator[](int n)
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;

        if (n < 0 || n > 10)
            exit(1);
        return arr[n];
    }

    void getVal();
};

void base::getVal()
{
    std::cout << "data " << data << std::endl;
}

int main()
{
    // level 1 - simple object creation, without parameter
    base obj;
    obj.getVal();

    // level 2 - uses parameterised constuctor
    base obj1(1);
    obj1.getVal();

    // level 3 - here copy constructor is run after overloaded increment operator is executed
    base obj2 = ++obj1;
    obj2.getVal();

    // level 3 - post-increment
    base obj3 = obj2++;
    obj3.getVal();

    // level 4 - arithmetic operation, unary overloaded operator
    base obj4 = obj3 + obj3;
    obj4.getVal();

    // level 4 - arithmetic operation, unary '-'
    base obj5 = obj4 - obj3;
    obj5.getVal();

    // level 4 - comparison operator
    if (obj5 < obj4)
        std::cout << "now you are familiar with how operator overloading looks & works\n";

    // level 5 - more similar type, with logically using the existing implementation
    if (obj4 > obj5)
        std::cout << "this operator doesn't require separate implementation\n";

    // level 5 - this too
    if (obj4 == obj4)
        std::cout << "and neither this\n";

    // level 6 - subscript operator
    obj[2] = 10;
    std::cout << obj[2] << std::endl;

    return 0;
}