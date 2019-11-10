#include "Auto.hpp"
#include <iostream>

int main()
{
    std::string pag = "PORSCHE";
    Auto porsche{pag};
    std::cout << porsche.getBrand();
    return 0x0;
}