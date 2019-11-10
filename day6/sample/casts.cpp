#include <iostream>

int main()
{
    auto array = new char[sizeof(int32_t)];
    int num = 187;
    memcpy(array, &num, sizeof(int32_t));
    int32_t maybe_num = *reinterpret_cast<int32_t*>(array);
    if (maybe_num == num)
    {
        printf("Woop Woop");
    }
}