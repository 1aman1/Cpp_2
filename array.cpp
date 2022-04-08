#include<array>
#include<iostream>
using namespace std;

int main() {
	array<int, 6> arr;

  	( arr.empty() == true ) ? cout << "empty\n" : cout << "not empty\n";
  
	arr.fill(0);

	for ( auto i : arr) cout << i << " "; cout << endl;

  	// reference to front and back
	arr.front() = arr.back() = 404;
  
  	// iterators
	//begin and end provide iterator
	for (auto it = arr.begin(); it != arr.end(); ++it)
		cout << *it << " "; cout << endl;
	
	array<int, arr.size()> dummy;
	arr.swap(dummy);

	for ( auto i : dummy ) cout << i << " "; cout << endl;

	for ( auto i : arr ) cout << i << " "; cout << endl;

	return 0;
}