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
	void eatyourfood()
	{
		cout << "Eating my burger\n";
	}
	void moveyorway()
	{
		cout << "I am walking now\n";
	}
};
class Animals : public livingthings
{
private:
	void eatyourfood()
	{
		cout << "Eating grass\n:";
	}
	void moveyorway()
	{
		cout << "jumping around\n";
	}
};
class Fish : public livingthings
{
private:
	void eatyourfood()
	{
		cout << "hanging out with turtles\n";
	}
	void moveyorway()
	{
		cout << "swimming around\n";
	}
};
class Birds : public livingthings
{
private:
	void eatyourfood()
	{
		cout << "eating worms\n";
	}
	void moveyorway()
	{
		cout << "flying\n";
	}
};

int main()
{
	livingthings *sth = new Humans;
	sth->eat();
	sth->move();
	delete sth;

	sth = new Birds;
	sth->eat();
	sth->move();
	delete sth;

	sth = new Fish;
	sth->eat();
	sth->move();
	delete sth;

	return 0;
}