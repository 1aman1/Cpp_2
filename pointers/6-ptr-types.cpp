#include <iostream>
#include <memory>
using namespace std;

class Base
{
public:
    void show()
    {
        cout << "Base::show()" << endl;
    }
};

int main()
{
    unique_ptr<Base> uPtrBase(new Base);
    uPtrBase->show();

    // returns the memory address of uPtrBase
    cout << uPtrBase.get() << endl;

    // transfers ownership to p2
    unique_ptr<Base> p2 = move(uPtrBase);
    p2->show();
    cout << uPtrBase.get() << endl;
    cout << p2.get() << endl;

    // transfers ownership to p3
    unique_ptr<Base> p3 = move(p2);
    p3->show();
    cout << uPtrBase.get() << endl;
    cout << p2.get() << endl;
    cout << p3.get() << endl;

    return 0;
}