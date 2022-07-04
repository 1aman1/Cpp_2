#include <iostream>
#include <vector>
using namespace std;
/*

			  ____________SHAPE_____________
			  |								|
	 _______areal____				___volumetric___
	 |	      |	    |				|		|      |
 circle    square	rectangle	  cube   cuboid  sphere

																						*/
class shape
{
public:
	virtual void design() = 0;
	virtual void intro() = 0;
};

class areal : public shape
{
public:
};

class volumetric : public shape
{
public:
	shape *ptr;
};

class rectangle : public areal
{
private:
	void design()
	{
		int l, b;
		cout << "length\t";
		cin >> l;
		cout << "breadth\t";
		cin >> b;
	}
	void intro()
	{
		cout << "rectangle\n";
	}
};

class sphere : public volumetric
{
private:
	void design()
	{
		int r;
		cout << "radius";
		cin >> r;
	}
	void intro()
	{
		cout << "sphere\n";
	}
};

class cuboid : public volumetric
{
private:
	void design()
	{
		int l, b, h;
		cout << "length\t";
		cin >> l;
		cout << "breadth\t";
		cin >> b;
		cout << "height\t";
		cin >> h;
	}
	void intro()
	{
		cout << "cuboid\n";
	}
};

class circle : public areal
{
private:
	void design()
	{
		int r;
		cout << "radius";
		cin >> r;
	}
	void intro()
	{
		cout << "circle\n";
	}
};

class square : public areal
{
private:
	void design()
	{
		int l;
		cout << "length\t";
		cin >> l;
	}
	void intro()
	{
		cout << "square\n";
	}
};

class cube : public volumetric
{
private:
	void design()
	{
		int l;
		cout << "length\t";
		cin >> l;
	}
	void intro()
	{
		cout << "cube\n";
	}
};

void run()
{
	vector<shape *> vec;
	int choice, more = 101;
	shape *ptr = NULL;
	while (more)
	{
		cout << "1 for circle\n"
			 << "2 square\n"
			 << "3 rectangle\n"

			 << "4 cube\n"
			 << "5 cuboid\n"
			 << "6 sphere\n"

			 << "0 for EXIT\n";
		cin >> choice;
		switch (choice)
		{
		case 1: // circle
		{
			ptr = new circle;
			ptr->design();
			vec.push_back(ptr);
			break;
		}
		case 2: // square
		{
			ptr = new square;
			ptr->design();
			vec.push_back(ptr);
			break;
		}
		case 3: // rectangle
		{
			ptr = new rectangle;
			ptr->design();
			vec.push_back(ptr);
			break;
		}
		case 4: // cube
		{
			ptr = new cube;
			ptr->design();
			vec.push_back(ptr);
			break;
		}
		case 5: // cuboid
		{
			ptr = new cuboid;
			ptr->design();
			vec.push_back(ptr);
			break;
		}
		case 6: // sphere
		{
			ptr = new sphere;
			ptr->design();
			vec.push_back(ptr);
			break;
		}
		case 0:
		{
			more = choice;
			break;
		}
		}
	} // end of while

	// display all the shapes
	cout << "\ndisplay the contents?\t[provide nonZero]\n";
	cin >> choice;
	if ((choice) && (!vec.empty()))
	{
		for (vector<shape *>::iterator i = vec.begin(); i != vec.end(); ++i)
		{
			shape *ptr = *(i);
			ptr->intro();
		}
	}
}

int main()
{
	bool tag = true;
	int choice = 0;
	while (tag)
	{
		run();
		cout << "\n\tREPEAT..!!\n";
		cin >> choice;
		tag = (choice == 0) ? false : true; // first default is false
	}
	system("pause");
}