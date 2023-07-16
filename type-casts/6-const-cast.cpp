#include <iostream>

void ModifyValue(const int &value)
{
    int &nonConstValue = const_cast<int &>(value);
    nonConstValue = 10;
}
/*
It's important to note that const_cast should be used with caution, and modifying a value through a const_cast should only be done when necessary and with a good understanding of the program's behavior.  */

int main()
{
    int number = 5;
    const int &constNumber = number;

    std::cout << "Before modification: " << number << std::endl;

    ModifyValue(constNumber);

    std::cout << "After modification: " << number << std::endl;

    return 0;
}
