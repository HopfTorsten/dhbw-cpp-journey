// using standard exceptions
#include <iostream>
#include <exception>
using namespace std;

class too_young_exception : public exception
{
    virtual const char *what() const throw() override
    {
        return "The person you wanted to date is not an adult!";
    }
};

int main()
{
    try
    {
        printf("How old are you? - %i\n", 16);
        too_young_exception ex;
        throw ex;
    }
    catch (exception &e)
    {
        cout << e.what() << '\n';
    }
    return 0;
}