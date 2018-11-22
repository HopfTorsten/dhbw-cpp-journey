#include <iostream>

typedef struct MY_STRUCT
{
    int x, y, z;
    char buf[255];
    int16_t shorty;

} my_struct_t;

union my_first_union
{
    int x;
    char c;
    int64_t longi
}

my_struct_t *createStruct()
{
    my_struct_t my_struct;
    return &my_struct;
}
int main()
{
    my_struct_t *structi = createStruct();
    structi->y = 0x5;
    printf("0x%X\n", structi->x);
}
