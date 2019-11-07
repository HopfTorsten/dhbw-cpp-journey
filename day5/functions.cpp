#include <functional>
#include <iostream>

int do_something_smart(int x, int y)
{
    return x + y;
}

int main()
{
    std::function<int(int,int)> smart = do_something_smart;
}