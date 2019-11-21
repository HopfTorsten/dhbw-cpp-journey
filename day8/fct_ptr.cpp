#include <iostream>
int sexy_function(int a, const char *my_string)
{
    return a * strlen(my_string);
}
int safe_function(int (*param)(int, const char *))
{
    std::cout << "Very safe" << std::endl;
    return param(5, "Wow");
}

typedef int (*func_type)(int, const char *);
using func_t = int (*)(int, const char *);
int main()
{
    auto x = sexy_function;
    int (*y)(int, const char *) = sexy_function;
    safe_function(x);
}