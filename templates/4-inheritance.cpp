#include <iostream>
using namespace std;

template <class T>
struct Base
{
    T p;
    Base() { cout << sizeof(p) << "Base\n"; }
};

template <class T, class U>
struct Derived : public Base<U>
{
    T q;
    Derived() { cout << sizeof(q) << "Derived\n"; }
};

int main()
{
    Base<short> bobj;
    cout << endl;

    Derived<int, long> dobj;

    return 0;
}