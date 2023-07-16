#include <iostream>

struct node
{
    int data;
    node *left;
    node *right;

    node(int v) : data(v),
                  left(nullptr),
                  right(nullptr){};

    node() = delete;
};

class Tree
{
private:
    node *_root;

    node *
    _insertUtility(node *, int);

    node *
    _removeUtility(node *, int);

    void
    _inOrder(node *);

public:
    Tree() { _root = nullptr; };

    // void
    // insert(int);

    // void
    // remove(int);

    // chaining
    Tree &
    insert(int);

    Tree &
    remove(int);

    node *
    findMin(node *);

    void print_inOrder();
};

void Tree::_inOrder(node *curr_node)
{
    if (curr_node)
    {
        _inOrder(curr_node->left);
        std::cout << curr_node->data << " : ";
        _inOrder(curr_node->right);
    }
}

void Tree::print_inOrder()
{
    if (_root)
        std::cout << "\nin-order-view -> ";
    else
        std::cout << "\n";

    _inOrder(_root);
}

node *Tree::_insertUtility(node *curr_node, int value)
{
    if (!curr_node)
    {
        return new node(value);
    }

    else if (value < curr_node->data)
    {
        curr_node->left = _insertUtility(curr_node->left, value);
    }

    else // if (value > curr_node->data)
    {
        curr_node->right = _insertUtility(curr_node->right, value);
    }

    return curr_node;
}

// void Tree::insert(int value)
// {
//     _root = _insertUtility(_root, value);
// }

Tree &Tree::insert(int value)
{
    _root = _insertUtility(_root, value);
    return *this;
}

node *Tree::_removeUtility(node *curr_node, int value)
{
    if (!curr_node)
    {
        return nullptr;
    }

    if (value < curr_node->data)
    {
        curr_node->left = _removeUtility(curr_node->left, value);
    }

    else if (value > curr_node->data)
    {
        curr_node->right = _removeUtility(curr_node->right, value);
    }

    else
    {
        if (curr_node->left == nullptr && curr_node->right == nullptr)
        {
            delete curr_node;
            return nullptr;
        }

        else if (curr_node->left != nullptr && curr_node->right == nullptr)
        {
            node *left_sub_tree = curr_node->left;
            delete curr_node;
            return left_sub_tree;
        }

        else if (curr_node->left == nullptr && curr_node->right != nullptr)
        {
            node *right_sub_tree = curr_node->right;
            delete curr_node;
            return right_sub_tree;
        }

        else
        {
            node *nextMin = findMin(curr_node->right);
            curr_node->data = nextMin->data;
            curr_node->right = _removeUtility(curr_node->right, nextMin->data);
        }
    }
}

// void Tree::remove(int value)
// {
//     _root = _removeUtility(_root, value);
// }

Tree &
Tree::remove(int value)
{
    _root = _removeUtility(_root, value);
    return *this;
}

node *Tree::findMin(node *curr_node)
{
    while (curr_node && curr_node->left)
    {
        curr_node = curr_node->left;
    }
    return curr_node;
}

int main()
{
    Tree obj;

    obj.insert(5).insert(3).insert(7).print_inOrder();

    obj.remove(3).print_inOrder();

    obj.insert(3).insert(11).insert(6).print_inOrder();

    obj.remove(7).print_inOrder();

    obj.insert(7).print_inOrder();

    obj.remove(3).remove(5).remove(6).print_inOrder();

    obj.remove(7).remove(11).print_inOrder();

    return 0;
}