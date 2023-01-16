#include <iostream>

int main()
{
  // BAD PRACTISE

  // stripping off constness for allowing re-assignment to variable which is originally constant

  const int a = 5;
  const int *Pa = &a;

  int *Qa = const_cast<int *>(Pa);

  *Qa *= 10;

  if (&a == Qa)
  {
    std::cout << "A: address-" << &a << " ,value-" << a << std::endl;
    std::cout << "Qa: address-" << Qa << " ,value-" << *Qa << std::endl;
  }

  // VALID PRACTISE

  int b = 15;
  const int *Pb = &b;

  int *Qb = const_cast<int *>(Pb);

  *Qb *= 10;

  if (&b == Qb)
  {
    std::cout << "B: address-" << &b << " ,value-" << b << std::endl;
    std::cout << "Qb: address-" << Qb << " ,value-" << *Qb << std::endl;
  }

  return 0;
}
