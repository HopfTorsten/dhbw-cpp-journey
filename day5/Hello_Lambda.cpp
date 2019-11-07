#include <iostream>
#include <functional>
void sneaky_call(std::function<void()> method)
{
  try
  {
    method();
  }
  catch (...)
  {
    //... silently take it
  }
}
int main()
{
  auto x = []() { std::cout << "Hello from lambda" << std::endl; };
  sneaky_call(x);
  return 0;
}
