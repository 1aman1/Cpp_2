#include <iostream>
#include <vector>

template <typename S>
class myStack
{
protected:
    std::vector<S> m_container;

public:
    myStack() { m_container.reserve(10); }

    S top();

    bool
    empty();

    int
    size();

    // modifiers
    void
        push(S);

    void
    pop();
};

template <typename S>
S myStack<S>::top()
{
    if (!m_container.empty())
        return m_container.back();
    else
        return -1;
}

template <typename S>
bool myStack<S>::empty()
{
    if (m_container.empty())
        return true;
    else
        return false;
}

template <typename S>
int myStack<S>::size()
{
    return m_container.size();
}

template <typename S>
void myStack<S>::push(S data)
{
    m_container.push_back(data);
}

template <typename S>
void myStack<S>::pop()
{
    if (!m_container.empty())
        m_container.pop_back();
}

template <typename S>
class InteractiveStack : public myStack<S>
{
public:
    InteractiveStack<S>() : myStack<S>(){};

    void menu();
};

template <typename S>
void InteractiveStack<S>::menu()
{

    int choice = 1, input;

    std::cout << "\n"
              << "1: top \n"
              << "2: push \n"
              << "3: pop \n"
              << "4: empty \n"
              << "5: size \n";

    while (choice)
    {
        std::cout << "Enter operation id !\n";
        std::cin >> input;

        switch (input)
        {

        case 1:
        {
            std::cout << "\nstack top :"
                      << myStack<S>::top();
            break;
        }

        case 2:
        {
            S value;
            std::cout << "\nPUSH : ";
            std::cin >> value;

            myStack<S>::push(value);

            break;
        }

        case 3:
        {
            myStack<S>::pop();
            break;
        }

        case 4:
        {
            std::cout << "\nis Empty : "
                      << std::boolalpha
                      << myStack<S>::empty();
            break;
        }

        case 5:
        {
            std::cout << "\nsize :"
                      << myStack<S>::size();
        }

        default:
        {

            std::cout << "\ninvalid operation\n";
        }
        }

        std::cout << "\ncontinue ? \t0 for quit : ";
        std::cin >> choice;
    }
}

int main()
{
    // myStack<int> obj;
    // obj.push(10);

    // std::cout << "\n"
    //           << obj.top();

    // obj.pop();

    // std::cout << "\n"
    //           << obj.top();

    InteractiveStack<int> obj;
    obj.menu();

    return 0;
}