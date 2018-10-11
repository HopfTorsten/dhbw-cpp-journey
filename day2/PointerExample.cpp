#include <stdio.h>

int main()
{
    long x = 9532523;
    long *x_ptr = &x;
    printf("Address: \n\t %p \n contains value:\n\t %d\n original val is: \n\t%d\n",
           x_ptr, *x_ptr, x);

    // in c and c++ arrays and pointers are somehow familiar with
    // each other. The pointer links to the first element of the
    // array
    char buf[50];
    char *string = buf;
    // will print all chars of the buf
    for (char *p = buf; *p; ++p)
    {
        printf("%c", *p);
    }

    // you can even use array operators on the pointer
    // this uses internaly the sizeof(char) to do this
    string[0] = 'a';
    string[1] = 'b';

    char letter = 'b';
    char *letterPointer = &letter;
    *letterPointer = '3';
    printf("Omg letter does not contain a letter anymore! but %c\n", letter);

    void *iCanPointToEverything = 0;
    char *iAmAString = "Vingardium Liviosa";
    // no problem
    iCanPointToEverything = iAmAString;
    //iAmAString = iCanPointToEverything; would need an explicit cast

    char *c_ptr = NULL;
    char *dont_dereference = nullptr;
    char *i_am_also_null = 0;

    //check if pointer is valid or at least not null
    if (c_ptr)
    {
        // do smth
    }

   

}