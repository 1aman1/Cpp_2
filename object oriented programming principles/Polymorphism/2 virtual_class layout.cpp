//#include<iostream>

class base
{
	char c1;
	int a;

public:
	virtual ~base() {}
	virtual void print() {}
};
class der1 : virtual public base
{
	int x;
	char y;

public:
	// virtual void print() {}
};
class der2 : virtual public base
{
	int x;
	char y;

public:
	// virtual void print() {}
};

class finalder : public der1,
				 public der2
{
};

int main()
{
	// base obj;
	//   return 0;
}
