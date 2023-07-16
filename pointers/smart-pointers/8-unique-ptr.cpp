#include <iostream>
#include <memory>
using namespace std;

class Base
{
public:
    int data;

    void myMethod()
    {
        cout << "Base::myMethod()" << endl;
    }
};

int main()
{
    unique_ptr<Base> uPtrBase(new Base);
    uPtrBase->myMethod();

    // returns the memory address of uPtrBase
    cout << uPtrBase.get() << endl;

    // transfers ownership to p2
    unique_ptr<Base> p2 = move(uPtrBase);
    p2->myMethod();
    cout << uPtrBase.get() << endl;
    cout << p2.get() << endl;

    // transfers ownership to p3
    unique_ptr<Base> p3 = move(p2);
    p3->myMethod();
    cout << uPtrBase.get() << endl;
    cout << p2.get() << endl;
    cout << p3.get() << endl;

    return 0;
}