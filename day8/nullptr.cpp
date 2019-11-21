#include <iostream>
void f(int x) { std::cout << "f(int)" << std::endl; }
void f(bool x) { std::cout << "f(bool)" << std::endl; }
void f(void *x) { std::cout << "f(void*)" << std::endl; }
int main()
{
    f(nullptr);
}