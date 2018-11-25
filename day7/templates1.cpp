
#include <iostream>
template <typename myType>
myType sum(myType a, myType b, myType c)
{
    return a + b + c;
}

int main()
{
    // template type is derived from input parameters
    auto result = sum(1, 5, 3);
    printf("Result: %i\n",result);
    auto double_result = sum(0.444,0.69,4213.22);
    printf("Result: %f \n",double_result);
}