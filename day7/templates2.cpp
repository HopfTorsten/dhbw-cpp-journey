#include <fstream>
#include <exception>
template <typename typ1>
typ1 readFromStream(std::ifstream &stream, char *dest)
{
    if (stream.is_open())
    {
        stream.read(dest, sizeof(typ1));
        typ1 *ptr = reinterpret_cast<typ1 *>(dest);
        return std::move(*ptr);
    }
    else
    {
        throw std::runtime_error("Could not read from file");
    }
}

int main()
{
    char *dest = new char[1024];
    try
    {
        std::ifstream stream("charakter.d2s");
        auto header = readFromStream<long>(stream, dest);
        printf("The correct header is: AA55AA55. File starts with %X\n", header);
    }
    catch (std::exception &ex)
    {
        printf("An error occured while reading the file: %s", ex.what());
        return -1;
    }
}