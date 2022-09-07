#include <iostream>
#include <vector>

template <typename S>
class Stack
{
protected:
    std::vector<S> stackVec;

public:
    Stack() { stackVec.reserve(10); }

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
S Stack<S>::top()
{
    if (!stackVec.empty())
        return stackVec.back();
    else
        return -1;
}

template <typename S>
bool Stack<S>::empty()
{
    if (stackVec.empty())
        return true;
    else
        return false;
}

template <typename S>
int Stack<S>::size()
{
    return stackVec.size();
}

template <typename S>
void Stack<S>::push(S data)
{
    stackVec.push_back(data);
}

template <typename S>
void Stack<S>::pop()
{
    if (!stackVec.empty())
        stackVec.pop_back();
}

template <typename S>
class InteractiveStack : public Stack<S>
{
public:
    InteractiveStack<S>() : Stack<S>(){};

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
                      << Stack<S>::top();
            break;
        }

        case 2:
        {
            S value;
            std::cout << "\nPUSH : ";
            std::cin >> value;

            Stack<S>::push(value);

            break;
        }

        case 3:
        {
            Stack<S>::pop();
            break;
        }

        case 4:
        {
            std::cout << "\nis Empty : "
                      << std::boolalpha
                      << Stack<S>::empty();
            break;
        }

        case 5:
        {
            std::cout << "\nsize :"
                      << Stack<S>::size();
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
    // Stack<int> obj;
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