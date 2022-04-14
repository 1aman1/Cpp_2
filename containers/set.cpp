#include<set>
#include<iostream>
#include<numeric>

using namespace std;

void print( const set<int>& s, int typ = 1) {
	cout << "set " << typ << ":";
	if ( !s.empty() )
		for ( auto i : s )	cout << " " << i;
	else
		cout << " empty";
	cout << endl;
}

int main() {
	set<int> s;
	int i = -5;

	while ( i ) {	s.insert(i);	++i;	}

	print(s);
	cout << s.count(-2) << endl;
	
	s.insert( -2 );
	cout << s.count(-2) << endl;
	
	print(s);
	s.erase(s.find(-2));
	print(s);

	s.clear();
	print(s);

	i = 5;
	while ( i ) {	s.emplace(i);	--i;	}

	print(s);

	return 0;
}
