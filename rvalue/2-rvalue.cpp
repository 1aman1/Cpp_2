#include <iostream>

int getValue()
{
	int ii = 10;
	return ii;
}

int main()
{
	std::cout << getValue();

	const int &val = getValue(); // OK
	// int &val2 = getValue();		 // NOT OK BCOZ
	// cannot bind non-const lvalue reference of type ‘int&’ to an rvalue of type ‘int’

	// rvalue ref makes both possible

	// where val3 accepts both lvalue and rvalues
	//  val4 will only accept temporary objects.

	const int &&val3 = getValue(); // OK
	int &&val4 = getValue();	   //  OK

	return 0;
}