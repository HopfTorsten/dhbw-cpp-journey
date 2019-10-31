#include <iostream>

typedef struct my_struct
{
    int x;
    int y;

    ~my_struct()
    {
        printf("Oh no my values have been x=%d,y=%d", x, y);
    }
} my_struct_t;

int main()
{
    my_struct_t instance;
    instance.x = 187;
    instance.y = 4711;
    return 0x00;
}