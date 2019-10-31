#include "CustomClass.hpp"
#include <iostream>

void CustomClass::doSomethigSmart(){
    printf("That was smart!");
}

int main(){
    CustomClass custom;
    custom.doSomethigSmart();
    return 0x0;
}
