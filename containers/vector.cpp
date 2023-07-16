// demostration of all vector function
#include <iostream>
#include <vector>
//#include<ctype.h> // to upper
#include <string>
#include <algorithm> // transform
//#include<iterator>
using namespace std;

void CBEGIN(vector<int> vec, string message)
{
	transform(message.begin(), message.end(), message.begin(), ::toupper);
	cout << endl
		 << message << "\t";
	if (vec.size() != 0)
		for (auto it = vec.cbegin(); it != vec.cend(); ++it)
			cout << *it << " ";
	else
		cout << "---FAILED-vector MIGHT be EMPTY";
	// cout << ::toupper;
}

int main()
{

	vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);

	for (auto &e : vec)
		cout << e << " ";
	cout << endl;

	// begin return iterator,MODIFIABLE
	for (auto it = vec.begin(); it != vec.end(); ++it)
		cout << *it << " ";
	cout << endl;

	// cbegin return the iterator/const iterator based on the const qualification of the object it is called upon.
	for (auto it = vec.cbegin(); it != vec.cend(); ++it)
		cout << *it << " ";
	//*it = 5; //denied
	cout << endl;

	// traverses like doubly linkedlist from the end
	for (auto it = vec.rbegin(); it != vec.rend(); ++it)
		cout << *it << " ";
	cout << endl;

	// similar to 'cbegin' with cocktail position
	for (auto it = vec.crbegin(); it != vec.crend(); ++it)
		cout << *it << " "; //*it = 5; //erraneous

	// assign values
	//  times, value
	vec.assign(4, 100);
	CBEGIN(vec, "assign");

	/*
	int arr[5] = {2,3,4,5,6};
	for( int i = 0; i < 3;++i ) {

		vec.assign(arr, arr+i);
		cout << "\nspace" << vec.size();
		CBEGIN(vec);
	}
	*/
	// vec.at(3) = 5;
	vec.assign(14, -1);
	vec.at(3) = 5;
	/*  1. It throws an error if the vector are not of the same type.
		2. It throws error if the vector are not of the same size.
		2. It has a basic no exception throw guarantee otherwise.*/

	vector<int> sw;
	sw.assign(3, 1);

	vec.swap(sw);
	CBEGIN(vec, "swap");
	CBEGIN(sw, "swap");

	// difference in  capacity and size [highly LOGICAL it is]
	cout << endl
		 << vec.size();
	cout << endl
		 << vec.capacity();

	// size reduces,,on erasing
	CBEGIN(vec, "erase");
	vec.erase(vec.begin() + 2);
	CBEGIN(vec, "erase");

	vec.clear();
	CBEGIN(vec, "erase");

	vec.assign(10, -1);
	auto it1 = vec.begin();
	auto it2 = vec.begin();
	vec.erase(it1, it2 + 4);
	CBEGIN(vec, "erasing with two iterator");

	// vec.reserve(size);
	// to provide minimum amount of memory allocated to vector

	// [] operator is used in similar manner as an array

	vec.emplace(vec.end(), 24);
	CBEGIN(vec, "emplace");
	//			iterator,, value
	vec.insert(vec.begin(), 4);
	CBEGIN(vec, "insert");
	//			iterator    times, value
	vec.insert(vec.begin(), 7, 4);
	CBEGIN(vec, "insert");

	cout << "\neoab:::";
	vector<int> V[3];
	V[0].push_back(3);
	V[1].push_back(3);
	for (int i = 0; i < 3; ++i)
		if (V[i].size() != 0)
			cout << V[i].at(0);

	cout << endl;
	//	system("Pause");
	return 0;
}
