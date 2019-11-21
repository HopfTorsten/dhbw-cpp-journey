#include <iostream>
int main()
{
    enum class Color // mit Gültigkeitsbereich
    {
        white,
        black,
        red
    };
    auto white = false;
    // no problemo

    // Color c = white ist nicht möglich

    Color c = Color::black;
    auto c2 = Color::red;
}
double multiply(double a, double b)
{
    return a * b;
}
void cNumsAreFun()
{
    enum state
    {
        ON,
        OFF
    };

    state x = ON;
    if (x < 2)
    {
        std::cout << "Did I just compare..." << std::endl;
        multiply(ON, 2.5);
        std::cout << "Did I just multiply..." << std::endl;
    }
}

void cppEnumsAreBetter()
{
    enum class state
    {
        ON,
        OFF
    };

    state x = state::ON; // nicht möglich
    if (x < 5)
    {
        // ...
    }
}