#pragma once
 
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>
 
template <class Container>
void split_by_comma(const std::string& str, Container& cont, char delim = ',')
{
    std::stringstream ss(str);
    std::string token;
    while (std::getline(ss, token, delim)) {
        cont.push_back(token);
    }
}

