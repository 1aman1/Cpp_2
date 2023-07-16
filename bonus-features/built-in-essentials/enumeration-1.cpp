#include <iostream>

enum dat
{
	a = -1,
	b,
	c = 4
} A;

int main()
{
	// predefined
	A = a;

	// later defined
	dat obj_1;
	dat obj_2;

	obj_1 = b;
	obj_2 = c;
	std::cout << A << obj_1 << obj_2 << std::endl;

	return 0;
}
