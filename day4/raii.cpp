#include <iostream>

typedef struct my_struct
{
    int x;
    int y;
    char * buffer;

    my_struct(int p_x,int p_y){
        x = p_x;
        y = p_y;
        buffer = new char[128];
    }

    ~my_struct()
    {
        printf("Oh no my values have been x=%d,y=%d", x, y);
        delete[] buffer;
    }
} my_struct_t;

int main()
{
    my_struct_t instance(187,4411);
    instance.x = 187;
    instance.y = 4711;
    return 0x00;
}