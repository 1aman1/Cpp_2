#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <map>
#include <bitset>
#include <list>

using namespace std;

struct base
{
	int *ptr;
	base()
	{
		cout << "0-arg ctor\n";
		this->ptr = new int;
		// more stuff
	}
	base(const base &rhs)
	{
		cout << "1-arg ctor\n";
		this->ptr = new int;
		// more stuff
	}

	~base()
	{
		cout << "dtor\n";
	}
};

int main()
{

	vector<base> arr;
	arr.push_back(base());

	/* the output will contain two ctor print statements,
	for pushing a temporary object an instance was already created at LINE 37,
	later another instance was created by the copy constructor
	..
	..
	destructor called
	destructor called


	Here in the situation above the copy constructor would pose a performance bottleneck for an amortized analysis.
	*/

	return 0;
}