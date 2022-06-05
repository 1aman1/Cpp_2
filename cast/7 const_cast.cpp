#include <iostream>

int main()
{
  const int a = 5;

  // stripped off constness using const_cast
  int *q = const_cast<int *>(&a);

  // allowing re-assignment to variable
  *q = 50;

  std::cout << a << " " << *q << std::endl;

  return 0;
}
