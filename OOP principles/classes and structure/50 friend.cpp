#include <iostream>
using namespace std;

class B;
class A
{
private:
  int a;

public:
  A() : a(0)
  {
  }
  void print()
  {
    cout << a;
    B b;
    b.printB();
    b.x;
  }
};

class B
{
private:
  int x;

public:
  B() : x(0)
  {
  }
  friend class A;
  /*void printB(){
    cout << x;
    A a;
    a.print();
    a.a;
  */
};

// line 16 & 31 give out that 'friend' relation is not commutative
// friendFn gains privilages to access the root,,,but the root doesnot get hold of the friend function

int main()
{
  return 0;
}
