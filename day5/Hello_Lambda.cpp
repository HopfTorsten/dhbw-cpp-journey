#include <iostream>

int main(){
  auto x = [](){std::cout << "Hello from lambda" << std::endl;};
  x();
  return 0;
}
