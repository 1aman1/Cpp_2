#include <iostream>
using namespace std;

class A
{
public:
    virtual void g() { std::cout << __PRETTY_FUNCTION__ << std::endl; }
};

class B : public A
{
public:
    void g() { std::cout << __PRETTY_FUNCTION__ << std::endl; }
};

class C : public B
{
public:
    void g() { std::cout << __PRETTY_FUNCTION__ << std::endl; }
};

class D : public C
{
public:
    void g() { std::cout << __PRETTY_FUNCTION__ << std::endl; }
};

A *f1()
{
    A *pa = new C;
    B *pb = dynamic_cast<B *>(pa);
    return pb;
}

A *f2()
{
    A *pb = new B;
    // the pointer to A holding object of type 'B' can't be typecast to a lower level in heirarchy
    // that is why the cast to C will result in seg-fault.
    // C *pc = dynamic_cast<C *>(pb);

    // But casting to B, will work just fine, because it is in the limit of heirarchy ladder, like an upgrade.
    B *pc = dynamic_cast<B *>(pb);

    return pc;
}

A *f3()
{
    A *pa = new D;
    B *pb = dynamic_cast<B *>(pa);
    return pb;
}

int main()
{
    f1()->g(); // (1)
    f2()->g(); // (2)
    f3()->g(); // (3)
    return 0;
}