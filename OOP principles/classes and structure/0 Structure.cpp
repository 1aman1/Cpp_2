// testing_programs_temp.cpp//
#include <iostream>
using namespace std;

class Distance
{
private:
	int feet;
	float inches;

public:
	Distance() : feet(0), inches(0.0)
	{
	}
	Distance(int ft, float in) : feet(ft), inches(in)
	{
	}
	void get_dist();
	void show_Distance();
	Distance operator+(Distance f) const;
};

void Distance::get_dist()
{
	cout << "enter the feet";
	cin >> feet;
	cout << "\nenter the inches\n";
	cin >> inches;
	cout << "\n";
}
void Distance::show_Distance()
{
	cout << feet << "\t" << inches << "\n";
}
Distance Distance::operator+(Distance f) const
{
	int ft = feet + f.feet;
	float in = inches + f.inches;
	while (in >= 12.00)
	{
		in -= 12.00;
		++ft;
	}

	return f;
}
void main()
{
	Distance dist1, dist3;
	Distance dist2(11, 6.25);

	dist1.get_dist();

	dist1.show_Distance();
	dist2.show_Distance();
	dist3.show_Distance();

	dist3 = dist2 + dist1;

	dist1.show_Distance();
	dist2.show_Distance();
	dist3.show_Distance();

	system("pause");
}