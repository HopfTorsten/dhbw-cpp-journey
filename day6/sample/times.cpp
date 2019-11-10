#include <functional>

template <typename... Args>
void times(int i, std::function<void(Args...)> f, Args... args)
{
    for (int c = 0; c < i; ++c)
        f(args...);
}
void some_func(int a, int b)
{
    printf("%d+%d=%d\n", a, b, a + b);
}
int main()
{
    std::function<void(int, int)> f = some_func;
    times(5, f, 1, 2);
}