#include <iostream>
typedef struct fun_struct{
    int32_t x;
    char magic[52];
} fun_struct_t;

int main(){

    fun_struct_t an_instance;

    size_t size_of_an_instance = sizeof(an_instance);

    fun_struct_t* another_instance = new fun_struct_t;

    size_t size_of_another_instance = sizeof(another_instance);

    printf("Size  of an_instance = %zu, size of another_instance = %zu \n"
     ,size_of_an_instance,size_of_another_instance);

    delete another_instance;
}