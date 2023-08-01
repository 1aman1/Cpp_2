#include <exception>
#include <memory>

class myFile
{
    std::unique_ptr<int> data;

public:
    myFile(int value = 1) : data(new int(value)) {}

    ~myFile() = default;
};

int main()
{
    try
    {
        myFile file(200);
    }
    catch (std::exception &e)
    {
    }

    return 0;
}