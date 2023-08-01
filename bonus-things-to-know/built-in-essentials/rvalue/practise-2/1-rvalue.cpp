#include <iostream>

/*
class test{};
*/

void fn(int &x)
{
	std::cout << __PRETTY_FUNCTION__ << x << std::endl;
}
void fn(int &&x)
{
	std::cout << __PRETTY_FUNCTION__ << x << std::endl;
}

int main()
{
	int i = 11;

	fn(i);
	fn(11);

	fn(std::move(i));

	return 0;
}