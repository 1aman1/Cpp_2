// #include<iostream>

class base
{
	short letter;
	int count;

public:
	virtual ~base() {}
	virtual void print() {}
};

class derived1 : virtual public base
{
	int x;
	short y;

public:
};

class derived2 : virtual public base
{
	int x;
	short y;

public:
};

class finalder : public derived1,
				 public derived2
{
};

int main()
{
	base obj;
	return 0;
}
