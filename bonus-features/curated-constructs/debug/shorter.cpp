#include <iostream>
#include <algorithm>

#ifndef DEBUG_LOG
#define DEBUG_LOG (std::find(argv, argv + argc, std::string("-debug")) != argv + argc)
#endif

int main(int argc, char *argv[])
{
    // Your main program logic here

    DEBUG_LOG ? std::cout << " This is a debug message\n" : std::cout << "";

    return 0;
}
