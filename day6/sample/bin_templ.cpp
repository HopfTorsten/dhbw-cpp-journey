#include <fstream>
#include <iostream>
template <typename type>
size_t write_binary(std::ostream &out, type &arg)
{
    out.write((char*)&arg, sizeof(type));
    return sizeof(type);
}
typedef struct mystruct
{
    int x = 5;
    int y = 4;
} struct_t;
int main()
{
    std::ofstream outstream("waste.bin", std::ios::out | std::ios::binary);
    struct_t t;
    auto x = write_binary<struct_t>(outstream, t);
    std::cout << x << " bytes written" << std::endl;
}