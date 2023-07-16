#include <iostream>

/*
A function in  base class gets inherited to derived class
when an object of derived class calls the function, the actual call is made to derived class function
this masks the function from base class, incase base version is required we use
using Base::fun;
*/

class Base
{
public:
	void fun() { std::cout << __PRETTY_FUNCTION__ << "\n"; }
};
class Derived : public Base
{
public:
	using Base::fun;

	void fun() { std::cout << __PRETTY_FUNCTION__ << "\n"; }
};

int main()
{
	Derived dObj;

	dObj.Base::fun();

	dObj.fun();

	return 0;
}