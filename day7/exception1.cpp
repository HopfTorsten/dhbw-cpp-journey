#include <iostream>

double divide(double a, double b)
{
    if (b == 0)
    {
        throw - 1;
    }
    return a / b;
}

int main()
{
    try
    {
        auto x = divide(4, 2);
        printf("Divided %f through %f result was: %f\n", 4.0, 2.0, x);
        auto y = divide(69.69, 0);
        printf("I am not sure if this gets printed\n");
        return 0;
    }
    catch (int ex)
    {
        printf("Caught exception!\n");
        return ex;
    }
}