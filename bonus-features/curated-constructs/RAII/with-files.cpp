#include <iostream>
#include <fstream>

class FileResource
{
public:
    FileResource(const std::string &filename) : file(filename)
    {
        if (!file.is_open())
        {
            throw std::runtime_error("Failed to open file: " + filename);
        }
        std::cout << "File opened: " << filename << std::endl;
    }

    void writeData(const std::string &data)
    {
        file << data;
    }

    ~FileResource()
    {
        if (file.is_open())
        {
            file.close();
            std::cout << "File closed." << std::endl;
        }
    }

private:
    std::ofstream file;
};

int main()
{
    try
    {
        // Using RAII with FileResource to manage file operations
        FileResource fileResource("example.txt");

        // Do something with the file
        fileResource.writeData("Hello, RAII!");

        // 'fileResource' will be automatically closed when it goes out of scope.
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
