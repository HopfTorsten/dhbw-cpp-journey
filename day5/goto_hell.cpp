#include <iostream>
#include <memory>

int do_something()
{
    printf("Complex stuff\n");
    return 0;
}
int do_something_else()
{
    printf("Complex stuff, too\n");
    return 0;
}

int main()
{
    int err = do_something();
    if (err)
    {
        goto error;
    }
    err = do_something_else();
    if (err)
    {
        goto error;
    }

    printf("all went well!");

error:
    return -1; // exit in error case

    return 0x0; // exit program normally 
}
