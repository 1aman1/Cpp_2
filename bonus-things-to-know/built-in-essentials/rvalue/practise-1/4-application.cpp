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
		this->ptr = new int;
		// more stuff
		cout << "0-arg ctor\n";
	}
	base(const base &rhs)
	{
		this->ptr = new int;
		// more stuff
		cout << "Copy ctor\n";
	}

	base(base &&dyingRhs) noexcept
	{
		this->ptr = dyingRhs.ptr;
		dyingRhs.ptr = nullptr;

		cout << "Move ctor\n";
	}

	~base()
	{
		cout << "dtor\n";
	}
};

#define USE_MOVE_SEMANTICS 1

int main()
{
	vector<base> arr;

	if (USE_MOVE_SEMANTICS)
	{
		arr.push_back(base());
	}
	else
	{
		base NOT_A_TEMPORARY_OBJECT;
		arr.push_back(move(NOT_A_TEMPORARY_OBJECT));
	}

	return 0;
}