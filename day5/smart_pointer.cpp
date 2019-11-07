#include <memory>

typedef struct my_struct
{
    my_struct(int a, int b) : x(a), y(b) {}
    int x;
    int y;
} my_struct_t;

typedef std::shared_ptr<my_struct_t> my_struct_ptr;

int main()
{
    my_struct_ptr smart_ptr = std::make_shared<my_struct_t>(187, 4711);
    return 0x00;
}