#include <iostream>

enum class classEnum
{
    Value1,
    Value2,
    Value3
};

// Wrapper class with implicit conversion to int
class EnumWrapper
{
public:
    EnumWrapper(classEnum value) : enumValue(value) {}

    operator int() const
    {
        return static_cast<int>(enumValue);
    }

private:
    classEnum enumValue;
};

int main()
{
    EnumWrapper myEnumValue = classEnum::Value2;

    int intValue = myEnumValue; // Implicit conversion to int

    std::cout << "myEnumValue: " << intValue << std::endl;

    return 0;
}
