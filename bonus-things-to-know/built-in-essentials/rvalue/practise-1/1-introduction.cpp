#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <map>
#include <bitset>
#include <list>

using namespace std;

void fn(int &v)
{
	cout << "normal ref\n";
}

void fn(int &&v)
{
	cout << "rval ref\n";
	// compiler will suit this one for all the temporary calls
	// like in regular return statement
}

int main()
{
	int i = 100;

	fn(i);
	fn(100);

	return 0;
}