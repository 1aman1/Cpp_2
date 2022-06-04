#include <iostream>
using namespace std;
int main()
{

  int num;
  cin >> num;

  // find number of 1 bits in binary format
  cout << __builtin_popcount(num) << endl;

  return 0;
}
