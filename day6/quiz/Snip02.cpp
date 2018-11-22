#include <iostream>

void printElements(int *int_array, size_t length);
void printElements(int *int_array, size_t length)
{
    for (int i = 0; i < length; ++i)
    {
        printf("[%d]: %d\n", i, int_array[i]);
    }
}

int main()
{
    int int_array[6] = {13,24,32,42,51,633};
    printElements(int_array,6);
}
