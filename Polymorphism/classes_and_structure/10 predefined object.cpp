#include <iostream>
class sth
{
	int s;
	std::string th;

public:
	sth()
	{
		std::cout << __PRETTY_FUNCTION__ << std::endl;
	}
	sth(std::string s)
	{
		std::cout << s << __PRETTY_FUNCTION__ << std::endl;
	}
} preDefObj;

int main()
{
	sth sth("2nd");
	return 0;
}
