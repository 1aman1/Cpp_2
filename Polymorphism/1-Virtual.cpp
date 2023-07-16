#include <iostream>
using namespace std;

class livingthings
{
public:
	void eat()
	{
		eatyourfood();
	}

	void move()
	{
		moveyorway();
	}

private:
	virtual void eatyourfood() = 0;
	virtual void moveyorway() = 0;
};

class Humans : public livingthings
{
private:
	void eatyourfood() override
	{
		cout << "Eating my burger\n";
	}
	void moveyorway() override
	{
		cout << "I am walking now\n";
	}
};
class Animals : public livingthings
{
private:
	void eatyourfood() override
	{
		cout << "Eating grass\n";
	}
	void moveyorway() override
	{
		cout << "jumping around\n";
	}
};
class Fish : public livingthings
{
private:
	void eatyourfood() override
	{
		cout << "hanging out with turtles\n";
	}
	void moveyorway() override
	{
		cout << "swimming around\n";
	}
};
class Birds : public livingthings
{
private:
	void eatyourfood() override
	{
		cout << "eating worms\n";
	}
	void moveyorway() override
	{
		cout << "flying\n";
	}
};

int main()
{
	livingthings *ptr = nullptr;

	ptr = new Humans;
	ptr->eat();
	ptr->move();
	delete ptr;

	ptr = new Birds;
	ptr->eat();
	ptr->move();
	delete ptr;

	ptr = new Fish;
	ptr->eat();
	ptr->move();
	delete ptr;

	ptr = new Animals;
	ptr->eat();
	ptr->move();
	delete ptr;

	return 0;
}