#include <iostream>

// Debug macro that prints debug information when enabled
#ifdef ENABLE_DEBUG
#define DEBUG_LOG(x) std::cout << "[DEBUG] " << x << std::endl;
#else
#define DEBUG_LOG(x)
#endif

int main(int argc, char *argv[])
{
    bool enableDebug = false;
    for (int i = 1; i < argc; i++)
    {
        if (std::string(argv[i]) == "-debug")
        {
            enableDebug = true;
            break;
        }
    }

// Define the macro ENABLE_DEBUG based on the command-line argument
#ifdef ENABLE_DEBUG
    if (enableDebug)
#define ENABLE_DEBUG
        else
#undef ENABLE_DEBUG
#endif

            // Now you can use the DEBUG_LOG macro throughout your code
            DEBUG_LOG("This is a debug message.");

    // Rest of your code goes here...

    return 0;
}
