#include <iostream>

int main()
{

  // bad practise
  const int a = 5;
  const int *Pa = &a;

  // stripped off constness using const_cast, for allowing re-assignment to variable
  // which was originally constant in nature
  int *Qa = const_cast<int *>(Pa);

  // 
  *Qa = 50;

  std::cout << a << " " << *Qa << std::endl;

  // good practise

  return 0;
}
