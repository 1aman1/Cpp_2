#include <iostream>
#include <sstream>

void printReverse(std::string str)
{
  std::string word, tmp;
  std::stringstream iss(str);
  while (iss >> tmp)
  {
    word = "." + word;
    word = tmp + word;
  }
  word.resize(word.length() - 1);
  std::cout << word;
}

int main()
{
  int noOfQ;
  std::string str;
  std::cin >> noOfQ;

  while (noOfQ--)
  {
    std::cin >> str;
    for (int i = 0; i < str.length(); ++i)
      if (str[i] == '.')
        str[i] = ' ';

    printReverse(str);
    // std::cout << ar;
    std::cout << std::endl;
  }
  return 0;
}
