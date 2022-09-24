#include <iostream>
#include <numeric>
#include <vector>

/* places


initialize a reference variable
 */
class Base
{

    int &ref;

public:
    Base();

    // FAIL
    // Base(int x) { ref = x; }

    // PASS
    Base(int x) : ref(x) {}
};

int main()
{

    Base obj(1);

    return 0;
}