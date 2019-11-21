#include "some_func.hpp"
int main()
{
    auto res = find_something();
    if (res == 0)
    {
        // Gibt die Methode einen Index,
        // ein Element oder einen Pointer zurück?
    }
}

#include "some_func.hpp"
int main()
{
    auto res = find_something();
    if (res ==  nullptr)
    {
        // Kann nur auf einen Pointer gelten
        // Kompiliert nicht bei Ganzzahlentyp
    }
}