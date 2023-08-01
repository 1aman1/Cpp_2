#include <iostream>
using namespace std;
int main()
{
	int i, j;
	while (true)
	{
		cout << "\nEnter a";
		cin.unsetf(ios::skipws);

		cin >> i;
		cout << cin.rdbuf();
		if (cin.good())
		{
			cin.ignore(10, '\n');
			break;
		}
		cin.clear();
		cout << "incorrect, please ";
		cin.ignore(10, '\n');
	}
	while (true)
	{
		cout << "\nEnter b";
		cin >> j;
		if (cin.good())
		{
			cin.ignore(10, '\n');
			break;
		}
		cin.clear();
		cout << "incorrect";
		cin.ignore(10, '\n');
	}
	cout << cin.rdbuf();
	system("pause");
	return 0;
}
