#include <iostream>
#include <vector>
#include <map>

class Person
{
public:
    Person(std::string name, int age) : name(name), age(age)
    {
        std::cout << "Constructor called for " << name << std::endl;
    }

    Person(const Person &other) : name(other.name), age(other.age)
    {
        std::cout << "Copy constructor called for " << name << std::endl;
    }

private:
    std::string name;
    int age;
};

int main()
{
    std::vector<Person> persons;

    // Person p1("Alice", 30);
    // persons.insert(persons.end(), p1);

    persons.emplace(persons.end(), "Alice", 30);

    return 0;
}
