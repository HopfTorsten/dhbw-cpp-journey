#pragma once
#include <string>
class Auto
{
private:
    std::string brand;

public:
    std::string &getBrand();
    Auto(std::string& p_brand);
};