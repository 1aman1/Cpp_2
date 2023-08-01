#include <iostream>
#include <algorithm>
/*
the chain a = b = c will work fine if a value is returned.

If you return a reference, minimal work is done. The values from one object are copied to another object.

However, if you return by value for operator=, you will call a constructor AND destructor EACH time that the assignment operator is called!!

a = b = c;
calls assignment operator twice, calls copy constructor twice, calls destructor type to delete the temporary values! Very wasteful and nothing gained! */

class Stationery
{
	int data;

public:
	Stationery() { std::cout << "def Ctor\n"; }

	Stationery(int x) : data(x) { std::cout << "1-arg Ctor\n"; }

	int lookInside() { return data; }

	// private: // this block enables copy construction & assignment operation
	Stationery(const Stationery &CC)
	{
		std::cout << "CC\n";
		this->data = CC.data;
	}

	Stationery &operator=(Stationery rhs)
	{
		if (this != &rhs)
		{
			std::cout << "OP =\n";

			//
			std::swap(data, rhs.data);
			// this->data = rhs.data;
		}
		return *this;
	};
};

int main()
{
	Stationery pencil(10);
	std::cout << pencil.lookInside() << "\nMade a Pencil\n";

	Stationery pen = pencil;
	std::cout << pen.lookInside() << "\nMade a Pen\n";

	Stationery marker, highlighter;
	marker = highlighter = pen;

	return 0;
}