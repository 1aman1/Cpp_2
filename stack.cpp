#include<stack>
#include<iostream>
using namespace std;

int main() {
    stack<int> myStack;

    myStack.empty() == true ?   cout << "empty\n" : cout << "not empty\n";

    for( int i = 0; i < 5; ++i )  myStack.push(i);

    myStack.empty() == true ?   cout << "empty\n" : cout << "not empty\n";

    cout << "stack size : " << myStack.size()  << endl;
    cout << "stack top : " << myStack.top()  << endl;

    myStack.pop();		
    myStack.pop();		

    cout << "stack top is " << myStack.top() << endl;

    return 0;
}
