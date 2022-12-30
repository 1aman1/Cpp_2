#include <iostream>

// call funciton inside base ctor, that is both in base and der

class base
{
public:
	base()
	{
		run();
	}

	void
	run()
	{
		std::cout << "run base\n";
	}
};

class Derived : public base
{
public:
	Derived() : base()
	{
		run();
	}

	void
	run()
	{
		std::cout << "run derived\n";
	}
};

int main()
{
	Derived o;

	// o.run();

	return 0;
}