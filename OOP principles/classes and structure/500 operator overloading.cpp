#include <iostream>

class Counter
{
private:
  size_t count;

public:
  Counter(int x = 0) : count(x)
  {
  }
  size_t getCounter()
  {
    return count;
  }

  Counter operator++()
  {
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    return Counter(++count); // nameless temporary object is used behind the scene
  }

  Counter operator++(int)
  { // postfix requires one parameter, to distinguish
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    return Counter(count++);
  }
};

int main()
{
  Counter obj;
  std::cout << obj.getCounter();

  Counter temp = obj++;
  std::cout << temp.getCounter();

  Counter temp2 = ++obj;
  std::cout << temp2.getCounter();

  return 0;
}
