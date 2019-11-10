#include "Auto.hpp"

std::string &Auto::getBrand()
{
    return this->brand;
}

Auto::Auto(std::string &p_brand) : brand(p_brand)
{
}