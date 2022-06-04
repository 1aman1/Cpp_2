class Employee
{
private:
	int id;

public:
	void show_id() {}
};

class Programmer : public Employee
{
public:
	void coding() {}
};

#include <typeinfo>

int main()
{
	Employee lee;
	Programmer park;

	Employee *pEmpA = &lee;
	Employee *pEmpB = &park;

	// check if two object is the same
	if (typeid(Programmer) == typeid(lee))
	{
		Programmer *pProg = (Programmer *)&lee;
		pProg->coding();
	}
	if (typeid(Programmer) == typeid(park))
	{
		Programmer *pProg = (Programmer *)&park;
		pProg->coding();
	}

	pEmpA->show_id();
	pEmpB->show_id();

	return 0;
}