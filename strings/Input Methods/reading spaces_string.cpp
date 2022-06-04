#include <iostream>

#define MAX 5

int main()
{
	char str1[MAX];

	std::cin.get(str1, MAX);
	std::cout << str1;

	return 0;
}
